words=["ciao", "lambda", "epsilon", "c++", "aaaaz", "zaaaa"]
reverse=lambda i: sorted(i, key = lambda sub: sub[::-1])
print(reverse(words))


import copy

class Sequence:

    def __init__(self,iterable):
        self.value = list(iterable)

    def __str__(self):
        return str(self.value)

    def __len__(self):
        return len(self.value)

    def __eq__(self,other):
        return self.value == other.value

    def __getitem__(self,index):
        return self.value[index]

    def __setitem__(self,key,newval):
        self.value[key] = newval

    def __delitem__(self,index):
        del self.value[index]

    def __iter__(self):
        return iter(self.value)

    def insert(self,key,newval):
        self.value.insert(key,newval)

    def append(self,newval):
        self.value.append(newval)

    def __copy__(self):
        return copy.deepcopy(self.value)


s1=Sequence(range(0,12))
print(s1)
s2=copy.copy(s1)
del s1[0]
s1.append(30)
print(s2)
