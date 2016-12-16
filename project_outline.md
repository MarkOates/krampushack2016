## KrampusHack Project Outline


TitleScreen
  Input:
    CursorUp
    CursorDown
    StartGame

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

