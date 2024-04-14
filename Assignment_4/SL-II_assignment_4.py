import re # import the regex module

# basic code to find the given string is a phone number or not 
def isPhoneNumber(text):
    if len(text) != 12:
        return False
    for i in range(0, 3):
        if not text[i].isdecimal():
            return False
    if text[3] != '-':
        return False
    for i in range(4, 7):
        if not text[i].isdecimal():
            return False
    if text[7] != '-':
        return False
    for i in range(8, 12):
        if not text[i].isdecimal():
            return False
    return True 
print('415-555-4242 is a phone number?')
print(isPhoneNumber('415-555-4242'))
print('"Moshi moshi" is a phone number?')
print(isPhoneNumber('Moshi moshi'))

message = 'call me at 415-555-1011 tomorrow. 415-555-9999 is my office.' 
for i in range (len(message) - 12 ):
    chunk = message [i:i + 12 ]
    if isPhoneNumber(chunk):
        print('phone number found: ' + chunk )
        print('done')

phoneNumRegex = re.compile(r'\d\d\d-\d\d\d-\d\d\d\d') # the phoneNumRegeX variable contains a regex object
# regex bbject 
#  \d means “a digit character”

# we could also use the other way around 
phoneNumRegex = re.compile(r'\d{3}-\d{3}-\d{4}')

#using r means that we are marking the string as a raw string , which does not escape characters
#  Python use the backslash (\)
# Typing r'\d\d\d-\d\d\d-\d\d\d\d' is much easier than typing '\\d\\d\\d-\\d\\d\\d-\\d\\d\\d\\d' .


matchobjects = phoneNumRegex.search('my number is 415-555-4242.')
# search() it searches inside the string entered into parantheses
print('phone number found : ' + matchobjects.group())

# group() method return a string of the actual matched text 

# grouping with parentheses 
# adding parentheses will create groups in the regex
phoneNumRegex = re.compile(r'(\d\d\d)-(\d\d\d-\d\d\d\d)')
matchobjects1 = phoneNumRegex.search('My Number is 415-555-4141.')
matchobjects1.group(1) # return the first set of parentheses
'415'
matchobjects1.group(2)
'555-4242'

# Passing 0 or nothing to the group() method will return the entire matched text
matchobjects1.group(0)
'415-555-4242'
matchobjects1.group()
'415-555-4242'

# if the phone number is enclosed in parentheses then we need to 
# escape the ( and ) this with a \

phoneNumRegex = re.compile(r'(\(\d\d\d\) (\d\d\d-\d\d\d\d))')
mo = phoneNumRegex.search('my phone number is (415) 555-4242.')

mo.group(1)
'(415)'
mo.group(2)
'555-4242'

# matching multiple groups with the pipe ( the same way we did with egrep)
# this works as a logical OR operator 
heroRegex = re.compile(r'Batman|Tina Fey')
mo1 = heroRegex.search('Batman and Tina Fey.')
mo1.group()
'Batman'

mo2 = heroRegex.search('Tina Fey and Batman.')
mo2.group()
'Tina Fey'

# matching several patterns starting with the same initial letters 

batRegex = re.compile(r'Bat(man|mobile|copter|bat)')
mo = batRegex.search('Batmobile lost a wheel')
mo.group()
'Batmobile'
mo.group(1) # just return the part of the text that is matched
'mobile'

# use \ for an actual charater that is to be matched 

#optional matching using a question mark

batRegex = re.compile(r'Bat(wo)?man')
# the part mentioned in the parentheses is optional text and must be preferred over the other if matched 
# the letter or bracket just before the ? makes the text optional 
mo1 = batRegex.search('the adventures of Batman')
mo1.group()
'Batman'

mo2 = batRegex.search('the adventures of Batwoman')
mo2.group()
'Batwoman'

# Matching Zero or More with the Star
#The * (called the star or asterisk) means “match zero or more” times

batRegex = re.compile(r'Bat(wo)*man')
mo1 = batRegex.search('The Adventures of Batman')
mo1.group()
'Batman'
mo2 = batRegex.search('The Adventures of Batwoman')
mo2.group()
'Batwoman'
mo3 = batRegex.search('The Adventures of Batwowowowoman')
mo3.group()
'Batwowowowoman'

# this is exactly the same way we did in egrep command 

#Matching One or More with the Plus
# While * means “match zero or more,” the + (or plus) means “match one or more.”

batRegex = re.compile(r'Bat(wo)+man')
mo1 = batRegex.search('The Adventures of Batwoman')
mo1.group()
'Batwoman'
mo2 = batRegex.search('The Adventures of Batwowowowoman')
mo2.group()
'Batwowowowoman'
mo3 = batRegex.search('The Adventures of Batman')
mo3 == None
True

# Matching Specific Repetitions with Curly Brackets

haRegex = re.compile(r'(Ha){3}')
mo1 = haRegex.search('HaHaHa newbies') 
mo1.group()
'HaHaHa'

mo2 = haRegex.search('Ha')
mo2 == None
True

# matching the greedy and the non greedy way 

greedyHaRegex = re.compile(r'(Ha){3,5}') # the greedy way, max of 3 to 5
mo1 = greedyHaRegex.search('HaHaHaHaHa')
mo1.group()
'HaHaHaHaHa'

nongreedyHaRegex = re.compile(r'(Ha){3,5}?') # ? implies the non greedy way 
mo2 = nongreedyHaRegex.search('HaHaHaHaHa')
mo2.group()
'HaHaHa'

# the findall() method 

phoneNumRegex = re.compile(r'\d\d\d-\d\d\d-\d\d\d\d') # has no groups
phoneNumRegex.findall('Cell: 415-555-9999 Work: 212-555-0000')
print('\n')
print("finadall() gives :")
print(phoneNumRegex.findall('Cell: 415-555-9999 Work: 212-555-0000'))
['415-555-9999', '212-555-0000']
print('\n')

# character classes 

# \d - for any numeric digit 
# \D - any character that is not numeric digit , negation of \d
# \w - any word character (including numeric digits)
# \W - negation of \w 
# \s - any space, tab , or newline character 
# \S - any Character that is not space, tab, or newline

# for example 

xmasRegex = re.compile(r'\d+\s\w+') # given pattern
print(xmasRegex.findall('12 drummers, 11 pipers, 10 lords, 9 ladies, 8 maids, 7 swans, 6 geese, 5 rings, 4 birds, 3 hens, 2 doves, 1 partridge'))
['12 drummers', '11 pipers', '10 lords', '9 ladies', '8 maids', '7 swans', '6 geese', '5 rings', '4 birds', '3 hens', '2 doves', '1 partridge']

# making our own character classes [aeiou]

vowelregex = re.compile(r'[aeiouAEIOU]')
vowelregex.findall("robocop Eats baby food. BABY FOOD.")
print("\n")
# returns all the occurences of a,e,i,o,u,A,E,I,O,U
print(vowelregex.findall("robocop Eats baby food. BABY FOOD."))

# the Caret ^ ( signifies beginning ) and dollar $ (signifies the end) Sign characters

beginwithhello = re.compile(r'^hello')
print(beginwithhello.search("hello world!"))

beginwithhello.search("he said hello.") == None # checks if this statement is true or not
True

endswithnumber = re.compile(r'\d$')
endswithnumber.search('your number is 49')

# now any number of patterns could be matched and searched using this learnt methods 


# the wildcard character ( . )
# the dot operator will match any character except newline.

atregex = re.compile(r'.at')
print(atregex.findall('the cat in the hat sat on the flat mat.'))

# matching everything with the dot-star (.*)

nameregex = re.compile(r'first name: (.*) last name: (.*)')
mo = nameregex.search('first name: albert last name: thompson')

print(mo.group(1))
print(mo.group(2))

# for non greedy way, use (.*?)

# Matching Newlines with the Dot Character
# \n newline character 
noNewlineRegex = re.compile('.*')
mao = noNewlineRegex.search('Serve the public trust.\nProtect the innocent. \nUphold the law.')
mao.group()
'Serve the public trust.'

newlineRegex = re.compile('.*', re.DOTALL)
newlineRegex.search('Serve the public trust.\nProtect the innocent. \nUphold the law.').group()
'Serve the public trust.\nProtect the innocent.\nUphold the law.'

# The ? matches zero or one of the preceding group(optional matching). also used for non greedy method 
# The * matches zero or more of the preceding group.
# The + matches one or more of the preceding group.
# The {n} matches exactly n of the preceding group.
# The {n,} matches n or more of the preceding group.
# The {,m} matches 0 to m of the preceding group.
# The {n,m} matches at least n and at most m of the preceding group.
# {n,m}? or *? or +? performs a nongreedy match of the preceding group.
# ^spam means the string must begin with spam.
# spam$ means the string must end with spam.
# The . matches any character, except newline characters.
# \d, \w, and \s match a digit, word, or space character, respectively.
# \D, \W, and \S match anything except a digit, word, or space character, respectively.
# [abc] matches any character between the brackets (such as a, b, or c).
# [^abc] matches any character that isn’t between the brackets.

# case in-sensitive matching 
# IGNORECASE ignores the case-sensitive letters
robocop = re.compile(r'robocop', re.IGNORECASE)

lmao = robocop.search("roBoCop is a part man , part machine , all cop.")
print("\n")
print(lmao.group())
'roBoCop'

# Substituting Strings with the sub() method

namesRegex = re.compile(r'Agent \w+')
namesRegex.sub('CENSORED', 'Agent Alice gave the secret documents to Agent Bob.')
'CENSORED gave the secret documents to CENSORED.'

# sub() function successfully substituted the given pattern ('CENSORED') in place of Agent \w*

# substituting a particular pattern in the given statemnet

agentnamesregex = re.compile(r'(\w)\w*')
agentnamesregex.sub(r'\1****', 'Agent alice told agent carol that agent eve knew agent bob was a double agent.')
 # \1 means ignore the first letter 

'A**** told C**** that E**** knew B**** was a double agent.'

#managing complex regexes 

# project phone number and Email extractor 
phoneRegex = re.compile(r'''(
    ( \d{3} | \(\d{3}\) )?        # area code
    (\s|-|\.)?                    # separator
    \d{3}                         # first 3 digits
    (\s|-|\.)                     # separator
    \d{4}                         # last 4 digits
    (\s*(ext|x|ext.)\s*\d{2,5})?  # extension
)''', re.VERBOSE)

# regex for email address 

emailregex = re.compile(r'''
    ([a-zA-z0-9._%+-]+  # username 
    @                   # @ symbol
    [a-zA-Z0-9.-]+      # domain name 
    (\.[a-zA-Z]{2,4})   # dot- something 
)''', re.VERBOSE)

# Assignment 4 , question 1: 
print('\n')
print('Assignment 4, Q1')

# validating the user credit card number 

credit_card_number = input("Enter your credit card number: ") 

is_credit_card_number = re.compile(r'^\d{4}-\d{4}-\d{4}-\d{4}$')
credit_regex = is_credit_card_number.search(credit_card_number) 

if credit_regex :
 print("True, it's a credit card number")
else :
    print("False, it's not a credit card number")

# validating PAN number 
    
PAN_card_number = input("Enter Your PAN card Number: ")
is_PAN_card_number = re.compile(r'^[A-Z]{5}\d{4}[A-Z]$')
PAN_regex = is_PAN_card_number.search(PAN_card_number)
print(PAN_regex)
if PAN_regex :
    print("True, it's a PAN card number")
else :
    print("False, it's not a PAN card number")

# validating Password 

Password = input("Enter password: ")
is_valid_password = re.compile(r'''(
                               ^[a-zA-Z]{1}              # ensures that the password begins with single letter 
                               ([a-z]|[A-Z]){3,4}        # ensures exactly three or four uppercase/lowercase letters
                               ([@$#_!%.]){1}            #  any one of these special symbols – ‘@’, ‘$’, ‘_’, ‘#’,‘!’, ‘%’, ‘.’.
                               \d{2,3}$                  # exactly two or three digits.
                               )''', re.VERBOSE)         # re.VERBOSE enables a more readable concise regex pattern 
Password_regex = is_valid_password.search(Password)

if Password_regex : 
    print("Yes, Strong Password")
else :
    print("No, Weak Password")
