## KrampusHack Project Outline


TitleScreen
  Actions:
    CursorUp
    CursorDown
    SelectOption
  Options:
    StartGame
    Exit
  State:
    ShowingTitle
    ItemSelected

StoryBoardScreen
  Input:
    Skip

GamePlayScreen
  States:
    Paused
    GetReady
    GamePlay
    ItemCollected
    TravelBetweenDoors
    BossFightWarmUp
    BossFight
    StageComplete
  Input:
    Pause
    Attack
    UseItem
    CollectChild
  Scene:
    Actors:
      PlayerCharacter
      Enemy (multiple types)
      Item
      Boss
      Door

