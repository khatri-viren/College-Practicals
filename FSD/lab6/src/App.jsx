import "./App.css";
import Header from "./components/Header";
import CreateArea from "./components/CreateArea";
import Note from "./components/Note";
import { useState } from "react";
// import dnotes from "./assets/notes";

function App() {
  const [notes, setNotes] = useState([]);

  const addNote = (newNote) => {
    setNotes((prevNotes) => [newNote, ...prevNotes]);
  };

  const updateNote = (id, editedTitle, editedContent) => {
    // console.log(editedContent, editedTitle);
    // return;

    setNotes((prevNotes) =>
      prevNotes.map((note) =>
        note.id === id
          ? { ...note, title: editedTitle, content: editedContent }
          : note
      )
    );
  };

  const deleteNote = (id) => {
    // console.log(id);
    // return;
    setNotes((prevNotes) => prevNotes.filter((note) => note.id !== id));
  };

  return (
    <>
      <Header />
      <CreateArea onAdd={addNote} />
      <h2 className="text-2xl font-semibold text-slate-800 px-10">
        Your Notes
      </h2>
      <hr className="mx-10 my-4" />
      {notes.length === 0 && (
        <div className="px-10 mx-auto w-fit block"> No Notes Created </div>
      )}
      <div className="grid grid-cols-4 gap-6 px-10">
        {notes.map((note, index) => {
          return (
            <Note
              id={note.id}
              key={index}
              title={note.title}
              content={note.content}
              onUpdate={updateNote}
              onDelete={deleteNote}
            />
          );
        })}
      </div>
    </>
  );
}

export default App;
