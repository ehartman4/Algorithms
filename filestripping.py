import string


def main():
    infile=open("essay.txt","r")
    #outfile=open("essaystrip.txt","w")
    text = infile.read()
    for i in range(len(text)):
        for j in range(len(string.punctuation)):
            if text[i] == string.punctuation[j]:
                text = text[:i] + text[(i+1):]
                break
    print(text)
    #string.lower
    
main()