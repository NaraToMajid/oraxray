const card = document.getElementById('card');

/**
 * Mengatur interaksi kursor dan efek tilt 3D
 */
card.addEventListener('mousemove', (e) => {
    const rect = card.getBoundingClientRect();
    
    // Posisi relatif mouse di dalam card
    const x = e.clientX - rect.left;
    const y = e.clientY - rect.top;

    // Set variabel CSS untuk digunakan di Masking dan Ring
    card.style.setProperty('--mouse-x', `${x}px`);
    card.style.setProperty('--mouse-y', `${y}px`);

    // Kalkulasi Tilt 3D
    const centerX = rect.width / 2;
    const centerY = rect.height / 2;
    const rotateX = (y - centerY) / 25;
    const rotateY = (centerX - x) / 25;

    card.style.transform = `rotateX(${rotateX}deg) rotateY(${rotateY}deg)`;
});

/**
 * Reset posisi saat kursor meninggalkan area kartu
 */
card.addEventListener('mouseleave', () => {
    card.style.transform = `rotateX(0deg) rotateY(0deg)`;
    
    // Sembunyikan lubang masking
    card.style.setProperty('--mouse-x', `-1000px`);
    card.style.setProperty('--mouse-y', `-1000px`);
});
