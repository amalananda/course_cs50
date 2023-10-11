const menuToggle = document.querySelector('.menu-toggle input');
const nav = document.querySelector('nav ul');

menuToggle.addEventListener('click', function () {
    nav.classList.toggle('slide');
});


    var nameNode = document.getElementById("name");
    nameNode.addEventListener("click", function () {
        alert("Welcome to my favourite sport players!")
    })