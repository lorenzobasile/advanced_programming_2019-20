
def is_palindrome(string_var):
    '''
    returns True if string_var is palindrome, False otherwise
    '''
    ret = True
    for i in range(len(string_var)//2):
        if string_var[i]!=string_var[-(i+1)]:
            ret=False
            break
    return ret

def histogram_letters(string_var):
    '''
    count how many times a letter is present in the string_var
    and returns a dict
    '''
    ret ={}
    for letter in string_var:
        if letter in ret:
            ret[letter]+=1
        else:
            ret[letter]=1
    return ret

def get_most_frequent(list_var):
    '''
    returns a tuple with the most frequent object in the list with the
    corresponing number
    '''
    occurrencies ={}
    for item in list_var:
        if item in occurrencies:
            occurrencies[item]+=1
        else:
            occurrencies[item]=1
    max_key=max(occurrencies, key=occurrencies.get)
    return (max_key, occurrencies[max_key])

def which_duplicates(list_var):
    '''
    return a dict with containing the repeted object and the number of repetitions
    '''
    occurrencies ={}
    duplicates ={}
    for item in list_var:
        if item in occurrencies:
            occurrencies[item]+=1
        else:
            occurrencies[item]=1
    for key,value in occurrencies.items():
        if value>1:
            duplicates[key]=value
    return duplicates


def compute_factorial(int_val):
    '''
    returns factorial of a number
    '''
    if int_val<2:
        return 1
    return int_val*compute_factorial(int_val-1)


def is_prime(int_val):
    '''
    returns True if int_val is prime, False otherwise
    '''
    if int_val<3:
        return True
    for i in range(2,int_val//2):
        if int_val%i==0:
            return False
    return True

print(is_palindrome("ciaooaic"))
print(histogram_letters("conteggio lettere"))
print(get_most_frequent([45,12,12,45,"pippo","ciao", "pippo", "pippo"]))
print(which_duplicates([45,12,12,45,"pippo","ciao", "pippo", "pippo"]))
print(compute_factorial(5))
print(is_prime(67))
