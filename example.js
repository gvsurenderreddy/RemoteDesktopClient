// Called by the common.js module.
function handleMessage(message_event) {
	var msg = message_event.data;
	common.logMessage("HandleMessage: " + msg);
}

var onLoginCkick = function (e) {
	var loginValue = document.getElementById('inputLogin').value;
	var passwordValue = document.getElementById('inputPassword').value;
	var domainValue = document.getElementById('inputDomain').value;
	common.naclModule.postMessage({cmd: 'loginCommand', login: loginValue, password: passwordValue, domain: domainValue });
};

function loadHandler() {
	document.getElementById('loginButton').addEventListener('click', onLoginCkick);
}

window.addEventListener('load', loadHandler);

