import { useState, useEffect } from "react";
import React from 'react';
import axios from 'axios'

function Forms() {
    const [title, setTitle] = useState('');
    const [description, setDescription] = useState('');
    const [author, setAuthor] = useState('');
    const [reading_time, setReadingTime] = useState('');

    let baseURL = "https://qghcujpqbvrdfszremfe.supabase.co/rest/v1/blogs"

    const handleSubmit = event => {
        console.log('Submitted Details are:');
        event.preventDefault();


        console.log('Title: ', title);
        console.log('Description:', description);
        console.log('Author:', author);
        console.log('Reading Time:', reading_time);


        setTitle('');
        setDescription('');
        setAuthor('');
        setReadingTime('');

        const blogdata = {
            title:title,
            description:description,
            author:author,
            reading_time:reading_time

        }
        
        axios.post(baseURL,blogdata, {
            headers: {
                'Authorization': 'Bearer eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJzdXBhYmFzZSIsInJlZiI6InFnaGN1anBxYnZyZGZzenJlbWZlIiwicm9sZSI6ImFub24iLCJpYXQiOjE2NTgxMjk3NzcsImV4cCI6MTk3MzcwNTc3N30.LvOp9lASnuJAAwvg2VxFmnrVXuqZOM0KVngw8EKHQcM',
                'apikey': 'eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJzdXBhYmFzZSIsInJlZiI6InFnaGN1anBxYnZyZGZzenJlbWZlIiwicm9sZSI6ImFub24iLCJpYXQiOjE2NTgxMjk3NzcsImV4cCI6MTk3MzcwNTc3N30.LvOp9lASnuJAAwvg2VxFmnrVXuqZOM0KVngw8EKHQcM'
            }
        }).then(console.log("done"));
    };

        return (
            <div>
                <form>

                    <div class="form-group row">
                        <label for="inputtitle" class="col-sm-2 col-form-label">Title:</label>
                        <div class="col-sm-10">
                            <input type="text" class="form-control" id="inputtitle" placeholder="Enter your title"  value={title}
onChange={event => setTitle(event.target.value)} />
                        </div>
                    </div>

                    <div class="form-group row">
                        <label for="inputdescription" class="col-sm-2 col-form-label">Description:</label>
                        <div class="col-sm-10">
                            <input type="text" class="form-control" id="inputdescription" placeholder="Enter description" value={description}
onChange={event => setDescription(event.target.value)} />
                        </div>
                    </div>

                    <div class="form-group row">
                        <label for="inputauthor" class="col-sm-2 col-form-label">Author name:</label>
                        <div class="col-sm-10">
                            <input type="text" class="form-control" id="inputauthor" placeholder="Enter author" value={author}
onChange={event => setAuthor(event.target.value)} />
                        </div>
                    </div>

                    <div class="form-group row">
                        <label for="input_reading_time" class="col-sm-2 col-form-label">Reading Time:</label>
                        <div class="col-sm-10">
                            <input type="number" class="form-control" id="input_reading_time" placeholder="Enter approximate reading time" value={reading_time}
onChange={event => setReadingTime(event.target.value)} />
                        </div>
                    </div>

                    <button type="submit" class="btn btn-primary" onClick={handleSubmit}>Submit</button>

                </form>
            </div>
        );
    
   
}

export default Forms;