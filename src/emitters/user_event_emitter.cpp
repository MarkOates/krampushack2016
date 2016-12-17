


#include <emitters/user_event_emitter.h>



UserEventEmitter::UserEventEmitter()
   : event_source()
{
   al_init_user_event_source(&event_source);
   al_register_event_source(Framework::event_queue, &event_source);
}



UserEventEmitter::~UserEventEmitter()
{
   al_unregister_event_source(Framework::event_queue, &event_source);
}



UserEventEmitter *UserEventEmitter::get_instance()
{
   if (!instance) instance = new UserEventEmitter();
   return instance;
}



void UserEventEmitter::emit_event(int32_t event_type)
{
   ALLEGRO_EVENT my_event;
   my_event.user.type = event_type;
   al_emit_user_event(&get_instance()->event_source, &my_event, NULL); // dtor is not needed for this type
}



UserEventEmitter *UserEventEmitter::instance = nullptr;



