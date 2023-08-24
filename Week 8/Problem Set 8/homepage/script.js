document.getElementById("feedback-form").addEventListener("submit", function(event) {
  event.preventDefault();

  const form = event.target;

  // Display the popup message
  const popup = document.createElement("div");
  popup.className = "popup";
  popup.textContent = "Your feedback has been noted!";
  document.body.appendChild(popup);

  // Remove the popup after 3 seconds
  setTimeout(function() {
    document.body.removeChild(popup);
  }, 3000);

  form.reset();
});
