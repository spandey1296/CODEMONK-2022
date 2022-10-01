function prime() {
   var number;
   let flag = 0;
   number = Number(document.getElementById("num").value);
   if (number){
      if (number <= 0){
         document.getElementById("ans").innerHTML = `${number} is netiher a Prime nor Composite number`;
         return
      }

      if (number == 1){
         document.getElementById("ans").innerHTML = `${number} is netiher a Prime nor Composite number`;
         return
      }
      for(let i =2; i<number; i++){
         if (number%i==0){
            document.getElementById("ans").innerHTML = `${number} is a Composite number`;
            flag = 1;
         }
      }
      if (flag == 0){
         document.getElementById("ans").innerHTML =  `${number} is a Prime number`;
      }
   }
   else{
      document.getElementById("ans").innerHTML =  `Enter a valid number`;
   }
 }