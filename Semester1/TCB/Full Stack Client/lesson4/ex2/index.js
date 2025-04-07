// 1
// for (let i=1; i<51; i++){
//     document.write(i + "<br>");
// }

// 2
// let str = prompt("Enter a long number: ");
// for (let i=0; i<str.length; i++){
//     if (parseInt(str[i]) % 2 != 0){
//         document.write(str[i] + "<br>");
//     }
// }

// 3
// let res = 0;
// for (let i=200; i<=300; i++){
//     res += i;
// }
// document.write(res + "<br>");

// 4
// for (let i=1000; i<10000; i++){
//     if (((parseInt(i/100))+(i%100))**2 == i){
//         document.write(i + "<br>");
//     }
// }

// 5
let num = parseInt(prompt("Enter a number: "));
let total = 0;
for (let i=1; i<num; i++){
    if (num % i == 0){
        total += i;
    }
}
if (total == num){
    alert("Perfect number");
}
else{
    alert("Not a perfect number");
}