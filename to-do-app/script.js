const addBtn = document.getElementById('addBtn');
const taskInput = document.getElementById('taskInput');
const taskList = document.getElementById('taskList');

addBtn.addEventListener('click', () => {
  const taskText = taskInput.value.trim();

  if (taskText === '') {
    alert('Please enter a task');
    return;
  }

  const li = document.createElement('li');
  li.className =
    "bg-gray-100 flex justify-between items-center px-3 py-2 rounded-lg hover:bg-purple-100 transition cursor-pointer";
  li.textContent = taskText;

  // Toggle complete
  li.addEventListener('click', () => {
    li.classList.toggle('line-through');
    li.classList.toggle('text-gray-500');
    li.classList.toggle('bg-purple-200');
  });

  // Delete button
  const delBtn = document.createElement('button');
  delBtn.textContent = 'X';
  delBtn.className =
    "ml-2 bg-gradient-to-r from-red-500 to-orange-400 text-white px-2 py-1 rounded hover:scale-110 transition";
  delBtn.addEventListener('click', (e) => {
    e.stopPropagation();
    li.classList.add('opacity-0', 'scale-90');
    setTimeout(() => li.remove(), 200);
  });

  li.appendChild(delBtn);
  taskList.appendChild(li);
  taskInput.value = '';
});
