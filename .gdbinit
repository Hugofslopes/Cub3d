# Disable debuginfod prompts
set debuginfod enabled off

# Enable pending breakpoints
set breakpoint pending on

# Improve print readability
set print pretty on
set print array on

# Enable syntax highlighting
set style enabled on

### Logging
#set logging on
#set logging overwrite on
#set logging redirect on
#set logging file gdb.txt


#Debug pipes
# set follow-fork-mode child
# set detach-on-fork off

#define ft_flood_fill
#	disp dup_grid[x][y]
#	disp x
#	disp y
#end

# Load the program
#file cub3d


# Set breakpoints
break main
break init
fs cmd

# Show active breakpoints and watchpoints
info break
info watch

run
