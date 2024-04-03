document.getElementById('loginForm').addEventListener('submit', function(event) {
    event.preventDefault();
    const username = document.getElementById('loginUsername').value;
    const password = document.getElementById('loginPassword').value;
    const data = {
        username: username,
        password: password
    };
    sendRequest('http://119.91.210.79:3000/login', 'POST', data);
});

document.getElementById('registerForm').addEventListener('submit', function(event) {
    event.preventDefault();
    const username = document.getElementById('registerUsername').value;
    const password = document.getElementById('registerPassword').value;
    const data = {
        username: username,
        password: password
    };
    sendRequest('http://119.91.210.79:3000/register', 'POST', data);
});


function sendRequest(url, method, data) {
    const xhr = new XMLHttpRequest();
    xhr.open(method, url, true);
    xhr.setRequestHeader('Content-Type', 'application/json');
    xhr.onreadystatechange = function() {
        if (xhr.readyState === XMLHttpRequest.DONE) {
            if (xhr.status === 200) {
                console.log(xhr.responseText);
                if (url.includes('/login')) {
                    handleLoginResponse(xhr.responseText);
                } else if (url.includes('/register')) {
                    handleRegisterResponse(xhr.responseText);
                }
            } else {
                console.error('Request failed:', xhr.status);
            }
        }
    };
    xhr.send(JSON.stringify(data));
}


function handleLoginResponse(response) {
    showModal('Login successful!');
}

function handleRegisterResponse(response) {
    showModal('Registration successful!');
}

// 显示模态框
function showModal(message) {
    const modal = document.createElement('div');
    modal.classList.add('modal');
    modal.innerHTML = `
        <div class="modal-content">
            <span class="close">&times;</span>
            <p>${message}</p>
        </div>
    `;
    document.body.appendChild(modal);

    const closeButton = modal.querySelector('.close');
    closeButton.addEventListener('click', function() {
        modal.style.display = 'none';
    });

    modal.style.display = 'block'; 
}



