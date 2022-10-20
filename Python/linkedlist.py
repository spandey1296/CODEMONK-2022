class node:
  def __init__(self,data,next=None):
        self.data = data
        self.next = next
    
    
  def __str__(self):
     return '{} {}'.format(self.data,self.next)

        
class linked:
    

    def __init__(self):
        self.head = None

    # def __str__(self):
    #     return '{}'.format(self.head)
        
    def link(self,data):
        Node=node(data,self.head)
        self.head=Node
       
        

        
    def display(self):
        if self.head==None:
            print("empty list")
        temp = self.head  
        while temp:
            print(temp.data," -->",end =" ")
            temp=temp.next

         
        
        
        
lk=linked()

lk.link(9)
lk.link(97)
lk.link(89)
lk.display()

