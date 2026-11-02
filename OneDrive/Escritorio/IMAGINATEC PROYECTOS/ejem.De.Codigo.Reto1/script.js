// Asegúrate de que el documento esté completamente cargado
document.addEventListener('DOMContentLoaded', function() {
   // Seleccionar el botón por su ID
    const contactButton = document.getElementById('contactButton');

   // Agregar el evento de clic al botón
    contactButton.onclick = function() {
    alert('Email: john.doe@example.com\nTeléfono: +123 456 7890');
};
});
