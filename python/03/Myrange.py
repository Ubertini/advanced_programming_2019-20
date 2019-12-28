class MyRange:
    """Myrange class """
    def __init__(self,*arguments):
        
        if(len(arguments)==3):
            self.start,self.stop,self.step = arguments
            if self.step==0: 
                raise ValueError("third argument must be different from zero")
            if (self.start>self.stop and self.step>0): 
                raise ValueError("start>stop --> step must be less then zero")
        
        elif(len(arguments)==2):
            self.start , self.stop = arguments
            self.step=1
            if(self.start>self.stop): raise ValueError("When two arguments are passed step is assumed to be equal 1, thus first argument must be smaller than the second one")
        
        elif(len(arguments)==1):
            self.stop=arguments[0]
            self.start=0
            self.step=1
        
        else:
            raise SyntaxError("too few or too many arguments (0 or >=4 arguments have been passed)")
        
        self.data = []
        i=self.start
        if(self.step>0):
            while(i<self.stop):
                self.data.append(i)
                i+=self.step
        else:
            while(i>self.stop):
                self.data.append(i)
                i+=self.step
        
        self.index=0


    def __iter__(self):
        self.index=0
        return self
    
    def __next__(self):
        if self.index == len(self.data):
            raise StopIteration
        self.index = self.index + 1
        return self.data[self.index-1]
    
    def __getitem__(self,key):
        return self.data[key]
    
    def __setitem__(self,key,item):
        self.data[key]=item
    
    def __str__(self):
        return 'MyRange:({},{},{})'.format(self.start,self.stop,self.step)




def myrange(*arguments):
    if(len(arguments)==3):
            start,stop,step = arguments
            if step==0: 
                raise ValueError("third argument must be different from zero")
            if (start>stop and step>0): 
                raise ValueError("start>stop --> step must be less then zero")
    
    elif(len(arguments)==2):
            start , stop = arguments
            step=1
            if(start>stop): raise ValueError("When two arguments are passed step is assumed to be equal 1, thus first argument must be smaller than the second one")
        
    elif(len(arguments)==1):
            stop=arguments[0]
            start=0
            step=1
        
        
    else:
            raise ValueError("too few or too many arguments (0 or >=4 arguments have been passed)")
    index=start
    if(start<stop):
        while(index<stop):
            yield start+index
            index+=step
    else:
        while(index>stop):
            yield index
            index+=step