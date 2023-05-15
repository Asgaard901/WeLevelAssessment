# WeLevelAssessment
This repository contains a solution by Jakub Vrtík to the task given by WeLevel.
Project was created using Unreal Engine version 5.2.0.

Description of my solution:

TargetActor (cpp)
- this actor contains the boolean value whose change we want to detect
- The boolean value is protected and can be set through the custom set function SetBooleanValue, which broadcasts the change using the event dispatcher OnBooleanValueChanged.

CustomAsyncNode (cpp)
- there is a custom async node AsyncTask_ListenForBooleanChange, which takes a TargetActor* argument
- the node automatically binds to TargetActor's event dispatcher on Activate() and unbinds in the event of node's destruction or if we explicitly call function StopListening()

BP_ListeningActor
- this is the blueprint actor, which utilizes the ListenForBooleanChange node
- actor is set to replicate by its properties, so his destruction will be replicated in multiplayer environments
- upon registering a change in the TargetActor's boolean value, ListeningActor destroys itself
- I also added some nodes for testing purposes with which you can play around

BP_TargetActor
- the only nodes present in the blueprint are there for testing purposes
- changes its boolean value every 2 seconds -> by default, the ListeningActor will destroy itself after 2 seconds
