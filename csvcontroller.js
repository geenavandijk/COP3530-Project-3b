const bodyParser = require('body-parser');
const Papa = require('papaparse'); // Assuming you intended to use Papaparse for CSV conversion

class CSVController {
    constructor(){}

    createCsv(items) {
        const csv = Papa.unparse(items, {
            header: true,
            encoding: 'UTF-16'
        });
        return csv; 
    }
}

module.exports = CSVController; 



// // TODO: define a proper endpoint to get YouTube data.
// app.get('/get-youtube-data', async (req, res) => {
//     try {
//         // Simulated response from YouTube API
//         const response = { items: [
//             { id: { vidId: '12345' }, snippet: { title: 'Video Title 1' } }, //
//             { id: { vidId: '67890' }, snippet: { title: 'Video Title 2' } }
//         ]};
// // unsure if this is how you search for specific data
//         const vidData = response.items.map(item => ({
//             vidID: item.id.vidId,
//             vidTitle: item.snippet.title
//         }));

//         const csv = Papa.unparse(vidData, {
//             header: true
//         });

//         res.attachment('videos.csv');
//         res.type('text/csv');
//         res.send(csv);

//         fs.writeFile('videos.csv', csv, (err) => {
//             if (err) {
//                 console.error('Cannot write to csv file', err);
//                 return;
//             }
//             console.log('CSV saved');
//         });
//     } catch (error) {
//         res.status(500).send(`Failed to process data: ${error.message}`);
//     }
// });
