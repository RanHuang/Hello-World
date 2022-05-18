from sys import argv

script, input_file = argv

def print_all(f):
    print f.read()

def rewind(f):
    f.seek(0)

def print_a_line(line_count, f):
#The readline() function returns the \n that is at the end of the line.
    print line_count, f.readline(),
# add an extra '\n' to the returned line
#    print line_count, f.readline()

current_file = open(input_file)

print "Print the whole file:\n"
print_all(current_file)

print "Rewind, kind of like a tape.\n"
rewind(current_file)

print "Print three lines:"

current_line = 1
print_a_line(current_line, current_file)

current_line += 1
print_a_line(current_line, current_file)

current_line += 1
print_a_line(current_line, current_file)
