const fileElement = document.getElementById("file");
const submitBtn = document.getElementById("submit");
const statusEl = document.getElementById("status");
const downloadLink = document.getElementById("download");

downloadLink.hidden = true;

let valid = false;
let url;

fileElement.addEventListener("change", () => {
  const file = fileElement.files[0];
  console.log(file);
  const maxSize = 1024 * 1024 * 5;

  if (file.size > maxSize) {
    valid = false;
  } else {
    valid = true;
    fname = URL.createObjectURL(file);
  }
});

submitBtn.addEventListener("click", (e) => {
  e.preventDefault();
  statusEl.innerText = valid ? "Valid" : "Not valid";
  if (valid) {
    downloadLink.hidden = false;
    downloadLink.href = fname;
  }
});
