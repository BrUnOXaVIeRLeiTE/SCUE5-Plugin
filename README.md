# {SCUE5}: Anti-Cheat Plugin for Unreal Engine 5

## Known Limitations:
* Build for UE5 Windows games only (64bit); (but it won't break packaging for other platforms).
* Only default ASCII characters are supported for text/string encryption.


## Requirements:
* Both Key Generator and the External Scanner requires VS2015 runtime dependencies to run.
* External Scanner also requires .NET 4 runtime dependencies.


## How To Use:
* Close UE5, unzip the files provided within the 'Plugins' directory into your UE5 game project's folder. Executable libraries and code will be added to your project's Plugins folder;
Then right click your .uproject file and choose 'Generate Visual Studio project files'. Then open the .uproject file; around ~1.6GB of C++ code will be generated, so be patient.
You may have to convert your project to C++ project first, simply adding an empty C++ Class to your game.

* Open your game project in Unreal Editor, click Edit and go to 'Project Settings..'-> 'Maps & Modes'; In 'Game Instance Class' field, set 'SafeGameInstance' class as default.
If you have another custom Game Instance, use it instead, but after installing the Secure-Client plugin you have to re-parent your Game Instance to be a child of SafeGameInstance.
This will activate the anti-cheat system for your game. If you want the anti-cheat tool-set disabled, just replace the default Game Instance again.

* To observe Game-Guard's behaviour while developing in Unreal Editor, and to activate the anti-debugger that is disabled by default, you have to:
- Create or re-parent a GameInstance Blueprint from the 'SafeGameInstance' class and set it as default in Project Settings.
- Uncheck the 'Hide Game-Guard' and 'Allow Debugging' check-boxes from the Details panel.
- You most likely don't want to block debugging while developing your game, uncheck it only when packaging in Shipping Mode and ready to publish.


## FAQs:
° What is the performance impact in game when using SC Safe Types in Blueprint graphs?
- The Safe Types provided to encrypt Blueprint properties have a very insignificant impact in your game code;
- Each call to a Get/Set node has a function footprint ranging from 0.00ms to 0.01 milliseconds.

° What about Garbage Collection, how these types deal with GC?
- The code generates no GC, UE5 will fire GC only when you destroy the Blueprint/Actor that was calling the Get/Set functions/nodes.

° Which Types are Safe Type supported?
- You can encrypt the usual types used for Blueprint properties, such as:

* Boolean
* Byte
* Integer
* Float
* Name
* String
* Text
* Vector
* Vector 2D
* Vector 4D
* Linear Color
* Rotator
* Transform

° Does Safe Types support SaveGame tag, to be recorded by the Auto-Save Plugin?
- Yes. Just enable SaveGame tag in advanced tab as usual and you easily get encrypted Save-Game data stored in your .sav files.

° Is networking, replication, supported for Safe Types?
- The idea is Yes, must be, but I'm still working on multiplayer code to make sure everything is bug-free when running in authoritative servers thus I'm not 100% sure on this one.

° Why I mark any Safe Type as 'editable', but values in Details panel are disabled and I can't change them?
- Because Safe Types are hidden and Unreal Engine's Editor doesn't know how to translate their encryption algorithm. Then what Details panel displays there is just a 'fake copy'
- of the real value which is possible to change or read only through the Get/Set node functions. If you could change values from Details panel, hackers could use the same route to
- trace the fake value and use it to change the real, encrypted one, without bothering with any encryption secrets.
- So to say, the only way you can change encrypted values is really through the Get/Set nodes which you can use in Blueprint graphs and/or its Construction Script to set default values.

° What if the Game-Guard external app gets cracked to never return any positives?
- Then your game itself through the SafeGameInstance class will take over and run an internal Game-Guard system; the class is built to force a crash in the game if a malicious app is running.
- This internal built-in code is compiled inside the game, packaged for Windows, and only runs slower than the external scanner, to not generate game-thread overhead.
You don't have to config anything for this, it's automatic; Just setup the required GameInstance class.


----- -----


[More Info]:

https://forums.unrealengine.com/t/plugin-anti-cheat-system/213948

--------------------------------------------------

**Copyright(C) Bruno Xavier B. Leite.**


#### LICENSE

THIS SYSTEM IS NOW PUBLISHED ON UNREAL ENGINE's MARKETPLACE
AND THE SAME THERMS FROM THEM APPLIES.

Please check Epic Games' therms here:
https://publish.unrealengine.com/faq


Unreal Marketplace page:
https://www.unrealengine.com/marketplace/scue4-anti-cheat-solution
