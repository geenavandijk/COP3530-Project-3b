
const express = require('express');
const path = require('path');
const Youtube = require('./ytcontroller');
const CSV = require('./csvcontroller');
const cors = require('cors');


const app = express();
// Enable cors for all.
app.use(cors());
const port = 3000;
const youtubeController = new Youtube();
const csvController = new CSV();

// Load a index.html file to add a query string and generate the results.
app.get('/', (req, res) => {
    res.sendFile(path.join(__dirname, './index.html'));
});

// Route: Query
// Description: Extracts the search parameter and calls the Youtube controller to 
// search with this query text.
app.get('/query', async (req, res) => {
    const searchQuery = req.query.search;
    console.log('Node: New query request received with param: ' + searchQuery);
    const data = await youtubeController.searchResults(searchQuery);
    // Send the result back.
    res.end(JSON.stringify(data));
});

app.get('/csv', (req, res) => {
    console.log('Node: New query request to create a CSV');
    const items = youtubeController.curItems; 
    const csv = csvController.createCsv(items);

    // Set the appropriate headers
    res.setHeader('Content-Type', 'text/csv');
    // Send the CSV file to the client
    res.attachment('videos.csv').send('\ufeff' + csv);
});

app.listen(port, () => {
    console.log(`Server is running on port ${port}`); // Changed from console.warn to console.log
});
