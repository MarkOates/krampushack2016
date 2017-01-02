



#include <framework/model3d.h>

#include <cstdio>
#include <iostream>
#include <allegro5/allegro_color.h>
#include <allegro5/allegro_primitives.h>
#include <framework/console_color.h>
#include <framework/vec3d.h>




Model3D::Model3D()
   : vertex_declaration(NULL)
   , vertexes()
   , texture(NULL)
{
   ALLEGRO_VERTEX_ELEMENT elems[] = {
      {ALLEGRO_PRIM_POSITION, ALLEGRO_PRIM_FLOAT_3, offsetof(ALLEGRO_VERTEX_WITH_NORMAL, x)},
      {ALLEGRO_PRIM_TEX_COORD, ALLEGRO_PRIM_FLOAT_2, offsetof(ALLEGRO_VERTEX_WITH_NORMAL, u)},
      {ALLEGRO_PRIM_COLOR_ATTR, 0, offsetof(ALLEGRO_VERTEX_WITH_NORMAL, color)},
      {ALLEGRO_PRIM_USER_ATTR, ALLEGRO_PRIM_FLOAT_3, offsetof(ALLEGRO_VERTEX_WITH_NORMAL, nx)},
      {0, 0, 0}
   };

   vertex_declaration = al_create_vertex_decl(elems, sizeof(ALLEGRO_VERTEX_WITH_NORMAL));
}




Model3D::~Model3D()
{
   al_destroy_vertex_decl(vertex_declaration);
}




bool Model3D::load_obj_file(const char *filename, float scale)
{
   clear();

   char buff[256];
   ALLEGRO_FILE* file = al_fopen(filename, "r");
   ALLEGRO_COLOR white = al_color_name("white");
   std::vector<ALLEGRO_VERTEX_WITH_NORMAL> vtxs;
   std::vector<vt_coord> vt_coords;
   std::vector<vec3d> vt_normals;
   ALLEGRO_VERTEX_WITH_NORMAL vtx;
   vt_coord vt_c;
   vec3d vt_normal;
   bool vertex_textures_found = false;
   bool vertex_normals_found = false;
   Model3D::named_object *current_named_object = NULL;

   if (!al_filename_exists(filename))
      std::cout << CONSOLE_COLOR_RED << "Could not load \"" << filename << "\" when creating Model3D" << CONSOLE_COLOR_DEFAULT << std::endl;

   while (al_fgets(file, buff, 256))
   {
      vtx.x = vtx.y = vtx.z = 0;
      vtx.color = white;
      vtx.u = vtx.v = 0;
      vtx.nx = vtx.nz = 0;
      vtx.ny = 1;

      int face_v1 = 0;
      int face_v2 = 0;
      int face_v3 = 0;
      int face_v4 = 0;

      int face_vt1 = 0;
      int face_vt2 = 0;
      int face_vt3 = 0;
      int face_vt4 = 0;

      int face_vn1 = 0;
      int face_vn2 = 0;
      int face_vn3 = 0;
      int face_vn4 = 0;

      if (strncmp(buff, "v ", 2) == 0)
      {
         sscanf(buff, "v %f %f %f", &vtx.x, &vtx.y, &vtx.z);
         vtxs.push_back(vtx);
      }
      else if (strncmp(buff, "vt ", 3) == 0)
      {
         vertex_textures_found = true;
         sscanf(buff, "vt %f %f", &vt_c.u, &vt_c.v);
         vt_c.u = vt_c.u;
         vt_c.v = 1 - vt_c.v;
         vt_coords.push_back(vt_c);
      }
      else if (strncmp(buff, "vn ", 3) == 0)
      {
         vertex_normals_found = true;
         sscanf(buff, "vn %f %f %f", &vt_normal.x, &vt_normal.y, &vt_normal.z);
         vt_normals.push_back(vt_normal);
      }
      else if (strncmp(buff, "o ", 2) == 0)
      {
         // grab the name of the object
         char namebuff[128];
         sscanf(buff, "o %127s", namebuff); 

         // create a new named object
         named_object new_named_object;
         new_named_object.identifier = namebuff;
         new_named_object.texture = NULL;
         named_objects.push_back(new_named_object);
         current_named_object = &named_objects.back();
      }
      else if (strncmp(buff, "f ", 2) == 0)
      {
         int num_vertexes_captured = 0;

         if (vertex_textures_found && vertex_normals_found)
         {
            num_vertexes_captured = 
               sscanf(buff, "f %d/%d/%d %d/%d/%d %d/%d/%d %d/%d/%d", &face_v1, &face_vt1, &face_vn1, &face_v2, &face_vt2, &face_vn2, &face_v3, &face_vt3, &face_vn3, &face_v4, &face_vt4, &face_vn4);
            num_vertexes_captured /= 3;
         }
         else if (vertex_textures_found)
         {
            num_vertexes_captured = 
               sscanf(buff, "f %d/%d %d/%d %d/%d %d/%d", &face_v1, &face_vt1, &face_v2, &face_vt2, &face_v3, &face_vt3, &face_v4, &face_vt4);
            num_vertexes_captured /= 2;
         }
         else if (vertex_normals_found)
         {
            num_vertexes_captured = 
               sscanf(buff, "f %d//%d %d//%d %d//%d %d//%d", &face_v1, &face_vn1, &face_v2, &face_vn2, &face_v3, &face_vn3, &face_v4, &face_vn4);
            num_vertexes_captured /= 2;
         }
         else
         {
            num_vertexes_captured = 
               sscanf(buff, "f %d %d %d %d", &face_v1, &face_v2, &face_v3, &face_v4);
         }

         vtx.x = vtxs[face_v1-1].x * scale;
         vtx.y = vtxs[face_v1-1].y * scale;
         vtx.z = vtxs[face_v1-1].z * scale;
         vtx.u = (vertex_textures_found ? vt_coords[face_vt1-1].u : 0);
         vtx.v = (vertex_textures_found ? vt_coords[face_vt1-1].v : 0);
         vtx.nx = (vertex_normals_found ? vt_normals[face_vn1-1].x : 0);
         vtx.ny = (vertex_normals_found ? vt_normals[face_vn1-1].y : 0);
         vtx.nz = (vertex_normals_found ? vt_normals[face_vn1-1].z : 1);
         vertexes.push_back(vtx);
         if (current_named_object) current_named_object->index_list.push_back(vertexes.size()-1);

         vtx.x = vtxs[face_v2-1].x * scale;
         vtx.y = vtxs[face_v2-1].y * scale;
         vtx.z = vtxs[face_v2-1].z * scale;
         vtx.u = (vertex_textures_found ? vt_coords[face_vt2-1].u : 0);
         vtx.v = (vertex_textures_found ? vt_coords[face_vt2-1].v : 0);
         vtx.nx = (vertex_normals_found ? vt_normals[face_vn2-1].x : 0);
         vtx.ny = (vertex_normals_found ? vt_normals[face_vn2-1].y : 0);
         vtx.nz = (vertex_normals_found ? vt_normals[face_vn2-1].z : 1);
         vertexes.push_back(vtx);
         if (current_named_object) current_named_object->index_list.push_back(vertexes.size()-1);

         vtx.x = vtxs[face_v3-1].x * scale;
         vtx.y = vtxs[face_v3-1].y * scale;
         vtx.z = vtxs[face_v3-1].z * scale;
         vtx.u = (vertex_textures_found ? vt_coords[face_vt3-1].u : 0);
         vtx.v = (vertex_textures_found ? vt_coords[face_vt3-1].v : 0);
         vtx.nx = (vertex_normals_found ? vt_normals[face_vn3-1].x : 0);
         vtx.ny = (vertex_normals_found ? vt_normals[face_vn3-1].y : 0);
         vtx.nz = (vertex_normals_found ? vt_normals[face_vn3-1].z : 1);
         vertexes.push_back(vtx);
         if (current_named_object) current_named_object->index_list.push_back(vertexes.size()-1);

         if (num_vertexes_captured == 4)
         {
            vtx.x = vtxs[face_v3-1].x * scale;
            vtx.y = vtxs[face_v3-1].y * scale;
            vtx.z = vtxs[face_v3-1].z * scale;
            vtx.u = (vertex_textures_found ? vt_coords[face_vt3-1].u : 0);
            vtx.v = (vertex_textures_found ? vt_coords[face_vt3-1].v : 0);
            vtx.nx = (vertex_normals_found ? vt_normals[face_vn3-1].x : 0);
            vtx.ny = (vertex_normals_found ? vt_normals[face_vn3-1].y : 0);
            vtx.nz = (vertex_normals_found ? vt_normals[face_vn3-1].z : 1);
            vertexes.push_back(vtx);
            if (current_named_object) current_named_object->index_list.push_back(vertexes.size()-1);

            vtx.x = vtxs[face_v4-1].x * scale;
            vtx.y = vtxs[face_v4-1].y * scale;
            vtx.z = vtxs[face_v4-1].z * scale;
            vtx.u = (vertex_textures_found ? vt_coords[face_vt4-1].u : 0);
            vtx.v = (vertex_textures_found ? vt_coords[face_vt4-1].v : 0);
            vtx.nx = (vertex_normals_found ? vt_normals[face_vn4-1].x : 0);
            vtx.ny = (vertex_normals_found ? vt_normals[face_vn4-1].y : 0);
            vtx.nz = (vertex_normals_found ? vt_normals[face_vn4-1].z : 1);
            vertexes.push_back(vtx);
            if (current_named_object) current_named_object->index_list.push_back(vertexes.size()-1);

            vtx.x = vtxs[face_v1-1].x * scale;
            vtx.y = vtxs[face_v1-1].y * scale;
            vtx.z = vtxs[face_v1-1].z * scale;
            vtx.u = (vertex_textures_found ? vt_coords[face_vt1-1].u : 0);
            vtx.v = (vertex_textures_found ? vt_coords[face_vt1-1].v : 0);
            vtx.nx = (vertex_normals_found ? vt_normals[face_vn1-1].x : 0);
            vtx.ny = (vertex_normals_found ? vt_normals[face_vn1-1].y : 0);
            vtx.nz = (vertex_normals_found ? vt_normals[face_vn1-1].z : 1);
            vertexes.push_back(vtx);
            if (current_named_object) current_named_object->index_list.push_back(vertexes.size()-1);
         }
      }
   }

   if (!vertex_normals_found) std::cout << "Vertex normals not found when loading \"" << filename << "\".  Unexpected results may occour with default vertex normal (0, 0, 1)." << std::endl;
   if (!vertex_textures_found) std::cout << "Vertex textures not found when loading \"" << filename << "\".  Unexpected results may occour." << std::endl;
   std::cout << named_objects.size() << " named objects found" << std::endl;

   al_fclose(file);
   return true;
}




void Model3D::inspect()
{
   for (unsigned i=0; i<vertexes.size(); i++)
      printf("[%d] %f %f %f : %f %f : %f %f %f\n", i, vertexes[i].x, vertexes[i].y, vertexes[i].z, vertexes[i].u, vertexes[i].v, vertexes[i].nx, vertexes[i].ny, vertexes[i].nz);
}




void Model3D::clear()
{
   vertexes.clear();
   named_objects.clear();
}




int Model3D::get_num_vertexes()
{
   return vertexes.size();
}




int Model3D::get_num_named_objects()
{
   return named_objects.size();
}




void Model3D::draw()
{
   if (vertexes.empty()) return;

   if (named_objects.empty())
   {
      al_draw_prim(&vertexes[0], vertex_declaration, texture, 0, vertexes.size(), ALLEGRO_PRIM_TRIANGLE_LIST);
   }
   else
   {
      // draw each of the named objects individually
      // TODO: this is not optimized, revisit this in the future
      for (unsigned i=0; i<named_objects.size(); i++)
      {
         draw_object(i);
      }
   }
}




bool Model3D::draw_object(int index)
{
   if (index < 0 || index > (int)named_objects.size()) return false;

   named_object &object = named_objects[index];

   al_draw_indexed_prim(&vertexes[0], vertex_declaration,
         (object.texture) ? object.texture : texture,
         &object.index_list[0], object.index_list.size(), ALLEGRO_PRIM_TRIANGLE_LIST);

   return true;
}




bool Model3D::draw_object(std::string name)
{
   bool object_exists = false;
   for (unsigned i=0; i<named_objects.size(); i++)
   {
      if (named_objects[i].identifier == name)
      {
         draw_object(i);
         object_exists = true;
      }
   }
   return object_exists;
}




void Model3D::set_texture(ALLEGRO_BITMAP *tx)
{
   texture = tx;
}




bool Model3D::set_named_object_texture(int index, ALLEGRO_BITMAP *tx)
{
   if (index < 0 || index > (int)named_objects.size()) return false;
   named_objects[index].texture = tx;
   return true;
}




bool Model3D::set_named_object_texture(std::string object_name, ALLEGRO_BITMAP *tx)
{
   bool object_exists = false;
   for (unsigned i=0; i<named_objects.size(); i++)
   {
      if (named_objects[i].identifier == object_name)
      {
         named_objects[i].texture = tx;
         object_exists = true;
      }
   }
   return object_exists;
}




void Model3D::scale(float scale)
{
   for (unsigned i=0; i<vertexes.size(); i++)
   {
      vertexes[i].x *= scale;
      vertexes[i].y *= scale;
      vertexes[i].z *= scale;
   }
}




vec3d Model3D::get_min_vertex_coordinate()
{
   if (vertexes.empty()) return vec3d(0, 0, 0);

   vec3d min_coord = vec3d(vertexes[0].x, vertexes[0].y, vertexes[0].z);
   for (unsigned i=1; i<vertexes.size(); i++)
   {
      if (vertexes[i].x < min_coord.x) min_coord.x = vertexes[i].x;
      if (vertexes[i].y < min_coord.y) min_coord.y = vertexes[i].y;
      if (vertexes[i].z < min_coord.z) min_coord.z = vertexes[i].z;
   }
   return min_coord;
}




vec3d Model3D::get_max_vertex_coordinate()
{
   if (vertexes.empty()) return vec3d(0, 0, 0);

   vec3d max_coord = vec3d(vertexes[0].x, vertexes[0].y, vertexes[0].z);
   for (unsigned i=0; i<vertexes.size(); i++)
   {
      if (vertexes[i].x > max_coord.x) max_coord.x = vertexes[i].x;
      if (vertexes[i].y > max_coord.y) max_coord.y = vertexes[i].y;
      if (vertexes[i].z > max_coord.z) max_coord.z = vertexes[i].z;
   }
   return max_coord;
}




