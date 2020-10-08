const container = document.querySelector('.container');
const besar = document.querySelector('.besar');
const thumbs = document.querySelectorAll(".thumb");

container.addEventListener('click', function(e){
    if(e.target.className == 'thumb'){
        besar.src = e.target.src; 
        besar.classList.add('fade');
        setTimeout(function(){
            besar.classList.remove('fade');
        },500);

        thumbs.forEach(function(thumb){
            thumb.className='thumb';
        });

        e.target.classList.add('aktif');
    }
});