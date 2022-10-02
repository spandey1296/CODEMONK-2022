let text=document.getElementById("textarea");
let check=document.getElementById("feature-flag");
function onLoad() {
    if(window.localStorage.getItem("autosave-data")) {
        text.value=window.localStorage.getItem("autosave-data") 
    }
}
function updateStorage() {
    setInterval(() => {
        let inputData = text.value;
        if(check.checked) {
            window.localStorage.setItem("autosave-data", inputData)
        }
    }, 1000);
}
onLoad()
updateStorage()