f1 = open("file1.txt","w")
f1.write("""File Handling in Python filter_none edit play_arrow brightness_4. 
The open command will open the file in... edit. play_arrow. brightness_4. The open command will open the file in the read mode and the for loop will print each...""")
f1.close()
f2= open("file1.txt")
print(f2.readlines())
f2.close()
f3=open("file1.txt","a")
f3.write("by kavin/n")

print(""".
.
.
.
.
.
""")
f3.close()
f3=open("file1.txt")
print(f3.readlines())
f3.close()
