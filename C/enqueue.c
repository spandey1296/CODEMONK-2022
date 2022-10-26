void insert(int data){
   int i =0;

   if(!isFull()){
      if(itemCount == 0){
         intArray[itemCount++] = data;        
      } else {
         for(i = itemCount - 1; i >= 0; i-- ){ 
            if(data > intArray[i]){
               intArray[i+1] = intArray[i];
            } else {
               break;
            }          
         }   
         intArray[i+1] = data;
         itemCount++;
      }
   }
}
