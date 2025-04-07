const images = [
    { src: 'img/pomeranian.png', description: 'Pomeranian' },
    { src: 'img/belgian_malinois.png', description: 'Belgian Malinois' },
    { src: 'img/german_sheperd.png', description: 'German Shepherd' },
    { src: 'img/giant_dane.png', description: 'Giant Dane' },
    { src: 'img/shiba_inu.png', description: 'Shiba Inu' },
    { src: 'img/siberian_husky.png', description: 'Siberian Husky' },
    { src: 'img/goldern_retriever.png', description: 'Golden Retriever' },
    { src: 'img/english_bulldog.png', description: 'English Bulldog' },
    { src: 'img/pug.png', description: 'Pug' },
    { src: 'img/rotweiller.png', description: 'Rottweiler' }
];
let currentIndex = 0;

function updateGallery() {
    const canvas = document.getElementById('galleryImage');
    const ctx = canvas.getContext('2d');
    const image = new Image();
    image.src = images[currentIndex].src;
    image.onload = () => {
        ctx.clearRect(0, 0, canvas.width, canvas.height);
        ctx.drawImage(image, 0, 0, canvas.width, canvas.height);
    };
    const imageDescription = document.getElementById('imageDescription');
    imageDescription.textContent = images[currentIndex].description;
}

document.getElementById('prevBtn').addEventListener('click', () => {
    currentIndex = (currentIndex > 0) ? currentIndex - 1 : images.length - 1;
    updateGallery();
});

document.getElementById('nextBtn').addEventListener('click', () => {
    currentIndex = (currentIndex < images.length - 1) ? currentIndex + 1 : 0;
    updateGallery();
});

updateGallery();