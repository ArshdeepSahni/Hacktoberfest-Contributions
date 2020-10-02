const image = document.querySelector('.img');
const title = document.getElementById('title');
const artist = document.getElementById('artist');
const music = document.querySelector('audio');
const progressContainer = document.getElementById('progress-container');
const progress = document.getElementById('progress');
const currentTimeEl = document.getElementById('current-time');
const durationEl = document.getElementById('duration');
const prevBtn = document.getElementById('prev');
const playBtn = document.getElementById('play');
const nextBtn = document.getElementById('next');

//songs data
const songs = [
	{
		name: 'Bare',
		displayName: 'Bare',
		artist: 'WILDES'
	},
	{
		name: 'Wonderful Tonight',
		displayName: 'Wonderful Tonight',
		artist: 'Eric Clapton'
	},
	{
		name: 'I Just Died In Your Arms',
		displayName: '(I Just) Died In Your Arms',
		artist: 'Cutting Crew'
	},
	{
		name: "Nature's Law",
		displayName: "Nature's Law",
		artist: 'Embrace'
	},
	{
		name: 'With Or Without You',
		displayName: 'With Or Without You',
		artist: 'U2'
	}
];

let isPlaying = false;

//play song function
function playSong() {
	isPlaying = true;
	playBtn.classList.replace('fa-play', 'fa-pause');
	playBtn.setAttribute('title', 'Pause');
	image.classList.toggle('img-play');
	music.play();
}

//pause song fuctiion
function pauseSong() {
	isPlaying = false;
	playBtn.classList.replace('fa-pause', 'fa-play');
	playBtn.setAttribute('title', 'Play');
	image.classList.toggle('img-play');
	music.pause();
}

//play button function call
playBtn.addEventListener('click', () => (isPlaying ? pauseSong() : playSong()));

//load new song
function loadSong(song) {
	title.textContent = song.displayName;
	artist.textContent = song.artist;
	music.src = `music/${song.name}.mp3`;
	image.src = `img/${song.name}.jpg`;
}

let songIndex = 1;

//next song function
function nextSong() {
	songIndex++;
	if (songIndex > songs.length - 1) songIndex = 0;
	loadSong(songs[songIndex]);
	if (isPlaying) image.classList.toggle('img-play');
	playSong();
}

//prev song function
function prevSong() {
	songIndex--;
	if (songIndex < 0) songIndex = songs.length - 1;
	loadSong(songs[songIndex]);
	if (isPlaying) image.classList.toggle('img-play');
	playSong();
}

loadSong(songs[1]);

//fill progress bar
function updateProgressBar(e) {
	if (isPlaying) {
		const { duration, currentTime } = e.srcElement;
		const progressPercent = currentTime / duration * 100;
		progress.style.width = `${progressPercent}%`;
		//duration calculation
		const durationMinutes = Math.floor(duration / 60);
		let durationSeconds = Math.floor(duration % 60);
		//extra zero
		if (durationSeconds < 10) {
			durationSeconds = `0${durationSeconds}`;
		}
		//avoiding NaN values
		if (durationSeconds) {
			durationEl.textContent = `${durationMinutes}:${durationSeconds}`;
		}
		//current time calculation
		const currentMinutes = Math.floor(currentTime / 60);
		let currentSeconds = Math.floor(currentTime % 60);
		//extra zero
		if (currentSeconds < 10) {
			currentSeconds = `0${currentSeconds}`;
		}
		currentTimeEl.textContent = `${currentMinutes}:${currentSeconds}`;
	}
}

//change current time function
function setProgressBar(e) {
	const width = this.clientWidth;
	const clickX = e.offsetX;
	const { duration } = music;
	music.currentTime = clickX / width * duration;
}

prevBtn.addEventListener('click', prevSong);
nextBtn.addEventListener('click', nextSong);
music.addEventListener('ended', nextSong);
music.addEventListener('timeupdate', updateProgressBar);
progressContainer.addEventListener('click', setProgressBar);
