function onLaunched(launchData) {
	chrome.app.window.create('index.html', { 
		width: 1024,
		height: 800
	});
}

chrome.app.runtime.onLaunched.addListener(onLaunched);
