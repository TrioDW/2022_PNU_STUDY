const express = require('express')
const app = express()
const port = 3000

app.use(express.static('public'))

app.get('/', (req, res) => res.send('Hello World!'))

// API 정보(부산광역시 생활필수품 가격 정보): https://www.data.go.kr/data/15034041/openapi.do
app.get('/market', function(req,res){
  var request = require('request');
  var options = {
    'method': 'GET',
    'url': 'http://apis.data.go.kr/6260000/BusanLifeInfoService/getLifeInfo?servicekey=1%2FrQf8T6jnJrnr11jpjmk%2FuylBLAfQH53XQD6rRqR93Ix%2Br9cvt1%2BrsvqGGAJMoQYdmrhm96xd3JpOnpaIOmvg%3D%3D&resultType=json',
    'headers': {
    }
  };
  request(options, function (error, response) { 
    if (error) throw new Error(error);
    console.log(response.body);
    res.send(response.body);
  });
})

app.get('/Path1', function (req, res) {
        res.send("GET Path1");
    })
app.get('/Path2', function(req,res) {
        res.send("GET Path2 : " + Date());
    })
app.put('/Path1', function (req, res) {
        res.send("PUT Path1");
    })

app.listen(port, () => console.log(`Example app listening at http://localhost:${port}`))