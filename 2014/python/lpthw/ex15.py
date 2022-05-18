from sys import argv

script, filename = argv

txt = open(filename, 'r')

print "Here is the content of your file %r:" % filename
print txt.read()
txt.close()

txt = open(filename, 'a')
txt.write('Open & Read')
txt.close()

print "Type a file to read again:"
file_again = raw_input('>')

txt_again = open(file_again)

print txt_again.read()
txt_again.close()
