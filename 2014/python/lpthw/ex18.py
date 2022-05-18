#This one is like your scripts with argv
def print_two_arguments(*args):
    arg1, arg2 = args
    print "arg1: %r, arg2: %r" % (arg1, arg2)

# ok, that *args is actually pointless, we can just do this
def print_two_arguments_again(arg1, arg2):
    print "arg1: %r, arg2: %r" % (arg1, arg2)

# this just takes one argument
def print_one_argument(arg1):
    print "arg1: %r" % arg1

# this one takes no arguments
def print_none_argument():
    print "I got nothing."

print_two_arguments("Nick", "Lily")
print_two_arguments_again("Nick", "Lily")
print_one_argument("First!")
print_none_argument()
