let totalBus = 10;
let busOperation = 6;

for(let noBus = 1; noBus <= totalhBus; noBus++) {
    if(noBus <= busOperation) {
        console.log('Bus Transjakarta ' + noBus + ' good bus operation.');
    } else if(noBus === 8) {
        console.log('Bus Transjakarta. ' + noBus + ' bus overtime.');
    } else {
        console.log('Bus Transjakarta. ' + noBus + ' bus stil didnt operation.');
    }
}