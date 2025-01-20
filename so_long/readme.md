
==========================================================================================================
// FLAGS USED FOR COMPILING MLX42

	The flags `-Wunreachable-code`, `-Ofast`, `-ldl`, `-lglfw`, `-pthread`, and `-lm` are used
	when compiling and linking programs with MLX42.

	`-Wunreachable-code` enables warnings for dead code,
	while `-Ofast` optimizes the program for maximum performance.

	`-ldl` links the dynamic linker library for runtime loading of shared libraries,
	and `-lglfw` links the GLFW library for window management and OpenGL context handling.

	`-pthread` adds multithreading support, and `-lm` links the math library for mathematical functions.
	These flags ensure MLX42 programs are optimized, functional, and linked to necessary dependencies.

	`-framework OpenGL` links the OpenGL framework for graphics rendering,
	and `-framework AppKit` links the AppKit framework for window management on macOS.
	These flags are necessary for MLX42 to handle graphics and GUI functionality on macOS systems.

==========================================================================================================

==========================================================================================================
// MAP VERIFICATIONS

	-> The map is surrounded with walls (1) [ If not return an error]
	-> The map should have at least one collectable (C)
	-> The map should have at least one exit (E)
	-> The map should have at least one player (P)
	-> The map should have a valid way to all the collectables and the exit
	-> The map should have a *.ber file extention

	-? If the map contains a duplicates characters (exit/start), you should display an error message

	[If any misconfiguration of any kind is encountered in the file, the program must exit in a clean way,
		and return "Error\n" followed by an explicit error message of your choice]

	EXIT =>
		-> print "Error\n --- The map should have..."

----------------------------------------------------------------------------------------------------------
// Map Parsing Steps

	a. Read the Map File
		The map is provided as a .ber file.
		Use get_next_line to read the map file line by line.
		Store the map in a 2D array (char **map) for easy access and manipulation.

	b. Validate the Map

		File Format:
			Ensure the file has a .ber extension.
			Ensure the file is readable and not empty.

		Map Structure:
			The map must be rectangular: All lines must have the same length.
			The map must be closed/surrounded by walls:
				The first and last rows must consist entirely of 1s (walls).
				The first and last characters of each row must be 1s.

		Map Content:
			Count the number of P, E, and C characters:
				Exactly one P (player).
				Exactly one E (exit).
				At least one C (collectible).
			Ensure no invalid characters are present (only 0, 1, C, E, P are allowed).

		Path Validation:
			Use a flood-fill algorithm (e.g., DFS or BFS) to check if:
				The player (P) can reach the exit (E).
				The player can collect all collectibles (C).


==========================================================================================================
