# Battleship

This repository contains a C project inspired by the Battleship game, developed for a programming course.

There are two versions of the program:

- `wargame.c`: a command-line version configured through terminal arguments.
- `projeto.c`: an interactive version that asks the user for the game options through menus.

## Purpose

The program generates and/or solves game boards using different game, positioning, and firing modes.

## Project Structure

- `wargame.c`: main implementation based on command-line arguments.
- `projeto.c`: interactive text-based version.
- `Guia de implementação.pdf`: technical implementation guide describing the internal logic and design decisions.
- `readme.txt`: short note included with the original submission.

## Compile and Get Started

Compile the two program variants with `gcc`:

```bash
gcc -o wargame wargame.c
gcc -o projeto projeto.c -lm
```

After compiling, you can start using the project in one of two ways.

Run the command-line version:

```bash
./wargame -h
```

Run the interactive version:

```bash
./projeto
```

If you want a quick first test, these commands are good starting points:

```bash
./wargame -t 9x9 -j 0 -p 1
./wargame -t 12x12 -j 1 -p 2 -1 2 -2 1 -3 1
./wargame -t 9x9 -j 2 -d 3 -1 1 -2 1 -3 1
```

## Command-Line Usage

Main options for `wargame`:

- `-t`: board dimensions in the format `rowsxcolumns`
- `-j`: game mode (`0`, `1`, or `2`)
- `-p`: positioning mode (`1` or `2`)
- `-d`: firing mode (`1` to `3`, used in game mode `2`)
- `-1` to `-8`: number of pieces of each type

## Game Modes

- `Mode 0`: generates and displays the board with the pieces already positioned.
- `Mode 1`: lets the player enter coordinates and try to discover all pieces.
- `Mode 2`: makes the computer fire automatically according to the selected firing mode.

## Positioning and Firing Modes

- `Positioning 1`: automatic placement of pieces according to the project rules.
- `Positioning 2`: automatic placement with user-defined quantities for each piece type.
- `Firing 1`: random coordinate selection without repetition.
- `Firing 2` and `3`: traverse `3x3` submatrices using a predefined sequence; mode `3` additionally marks cells around discovered pieces to avoid redundant shots.

## Technical Summary

The program is built around in-memory matrices, with the main board indexed as `yx[y][x]`. The implementation organizes the board into `3x3` blocks, and this structure drives both piece placement and automatic firing behavior. The `Guia de implementação.pdf` file contains the detailed technical explanation, including auxiliary matrices, flags, and validation logic used throughout the program.

## Notes

- Valid board dimensions must be multiples of `3`, within the limits defined in the code.
- The original submission includes a note about a restriction involving firing mode together with game modes `0` and `1`, due to a possible conflict with the provided course script.
- `projeto.c` includes presentation and usability improvements over `wargame.c` while keeping the same core functionality.
