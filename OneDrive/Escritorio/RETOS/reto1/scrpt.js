document.getElementById("checkButton").onclick = function() {
    const url = document.getElementById("urlInput").value;

    if (url) {
        document.getElementById("result").innerText = "Si Existe tu URL!.";
    } else {
        document.getElementById("result").innerText = "Por favor, introduce una URL.";
    }
};
