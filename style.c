* {
    margin: 0;
    padding: 0;
    box-sizing: border-box;
}

body {
    background-color: #050505;
    display: flex;
    justify-content: center;
    align-items: center;
    height: 100vh;
    overflow: hidden;
}

.wrapper {
    perspective: 1200px;
}

.reveal-card {
    position: relative;
    width: 70vw;
    max-width: 400px; 
    aspect-ratio: 3 / 4; 
    border-radius: 30px;
    overflow: hidden;
    box-shadow: 0 40px 80px rgba(0,0,0,0.9);
    cursor: none; /* Sembunyikan kursor asli */
    border: 1px solid rgba(255, 255, 255, 0.1);
    transition: transform 0.1s ease-out;
    background-color: #000;
}

.image-base {
    width: 100%;
    height: 100%;
    object-fit: cover;
    display: block;
}

.image-overlay {
    position: absolute;
    top: 0;
    left: 0;
    width: 100%;
    height: 100%;
    background-image: url('foto1.webp');
    background-size: cover;
    background-position: center;
    z-index: 2;
    
    /* Logika Masking Kecil (80px) */
    -webkit-mask-image: radial-gradient(
        80px circle at var(--mouse-x) var(--mouse-y),
        transparent 0%,
        transparent 50%,
        black 100%
    );
    mask-image: radial-gradient(
        80px circle at var(--mouse-x) var(--mouse-y),
        transparent 0%,
        transparent 50%,
        black 100%
    );
}

.cursor-ring {
    position: absolute;
    width: 160px; /* 2x radius mask */
    height: 160px;
    border: 1px solid rgba(255, 255, 255, 0.4);
    border-radius: 50%;
    pointer-events: none;
    transform: translate(-50%, -50%);
    left: var(--mouse-x);
    top: var(--mouse-y);
    z-index: 3;
    box-shadow: 0 0 15px rgba(255,255,255,0.1);
}
