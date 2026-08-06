# Pikmin 2 Enemy Drop Mod
Decomp code edits needed to make the drop mod work in our implementation

## Notes
- Uses two mem addresses for handling things, each with a specific starting value:
  1. 0xBADABADA = where enemy drop IDs go
  2. 0xBEDEBEDE = where drop IDs are put after a successful drop, to track if it was successfully handled
- The above may change in memory but I haven't learned how to make the game save the pointers somewhere useful yet <3 sorgy
  - I've just been using Dolphin Memory Engine to search for the values tbh
- **Requires** you to max out the emulated RAM and enable MMU in Dolphin
  - This mod changes the max heap size for enemy allocation so it can fit things in
  - Enemy memory is pre-allocated so it also adds generators with sane limits for enemies that are desired
  - See `src/plugProjectKandoU/baseGameSection.cpp` (search for "drop marker") to change the enemy gens
- This is really just kinda cobbled together, idk what i'm doing lmaoooo