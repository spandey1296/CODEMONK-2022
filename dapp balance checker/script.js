let web3= new Web3(Web3.givenProvider || "https://mainnet.infura.io/v3/4c86cc821683429ba60bc7e068e4d064");

const getBalanceFun = async (address) => {
    const getBal = await web3.eth.getBalance(address)
    const amtConversion = await web3.utils.fromWei(getBal)
    document.getElementById("balance").innerHTML = amtConversion + " ETH"
    document.getElementById("input-value").value="";
}

document.getElementById("btn").addEventListener("click", () => {

   let inputVal= document.getElementById("input-value").value;
   if(inputVal === '' || inputVal === undefined){
    alert("Please enter your wallet address")
   }else{
    getBalanceFun(inputVal);
   }
})