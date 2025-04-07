function BaseConvert() {
    var from = document.querySelector('input[name="fromBase"]:checked').value;
    var to = document.querySelector('input[name="toBase"]:checked').value;
    var num = document.getElementById("num").value;
    var result = parseInt(num, from).toString(to);
    document.getElementById("result").innerHTML = `Result is: ${result}`;
}