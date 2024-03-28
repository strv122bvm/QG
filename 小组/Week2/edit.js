let notes = [];

function addNote() {
    const noteInput = document.getElementById('note-input');
    const noteText = noteInput.value.trim();
    if (noteText !== '') {
        notes.unshift(noteText);
        renderNotes();
        noteInput.value = '';
    }
}

function handleKeyPress(event) {
    const keyCode = event.keyCode || event.which;
    if (keyCode === 13) { 
        addNote();
    }
}


function deleteNote(index) {
    notes.splice(index, 1);
    renderNotes();
}

function editNote(index) {
    const newNote = prompt('修改笔记：', notes[index]);
    if (newNote !== null) {
        notes[index] = newNote.trim();
        renderNotes();
    }
}

function searchNotes() {
    const searchInput = document.getElementById('search-input').value.trim().toLowerCase();
    const notesList = document.getElementById('notes-list');
    notesList.innerHTML = '';

    notes.forEach((note, index) => {
        const regex = new RegExp(searchInput, 'gi');
        const highlightedNote = note.replace(regex, match => `<span class="search-highlight">${match}</span>`);
        if (highlightedNote !== note) {
            const noteElement = document.createElement('div');
            noteElement.classList.add('note');
            noteElement.innerHTML = `${highlightedNote}
                                     <button onclick="editNote(${index})">编辑</button>
                                     <button onclick="deleteNote(${index})">删除</button>`;
            notesList.appendChild(noteElement);
        }
    });
}

function renderNotes() {
    const notesList = document.getElementById('notes-list');
    notesList.innerHTML = ''; //将容器的内部 HTML 内容设置为空字符串
    notes.forEach((note, index) => {
        const noteElement = document.createElement('div'); //创建一个新的笔记元素
        noteElement.innerHTML = `<div class="note">${note}</div>
                                 <button onclick="editNote(${index})">编辑</button>
                                 <button onclick="deleteNote(${index})">删除</button>`;
        notesList.appendChild(noteElement); //将笔记元素添加到笔记列表容器中
    });
}

//在页面加载时渲染笔记列表
renderNotes();
