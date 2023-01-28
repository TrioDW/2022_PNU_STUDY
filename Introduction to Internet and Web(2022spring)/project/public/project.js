
function stack_L() {

  document.getElementById('basic_info').style.display="table"
  document.getElementById('basic_info').style.visibility="visible"

  var xhr = new XMLHttpRequest();
  xhr.withCredentials = true;
  var companyname = document.querySelectorAll("input")[0].value;

  console.log(companyname);
  xhr.addEventListener("readystatechange", function() {
    if(this.readyState === 4) {

      parser = new DOMParser();
      var comp = parser.parseFromString(this.responseText,"text/xml");

      for( let i=0 ; i < 10 ; i++ ) {
        var table = document.getElementById('basic_info');
        var row = table.insertRow();
        var cell1 = row.insertCell(0);
        var cell2 = row.insertCell(1);
        var cell3 = row.insertCell(2);
        var cell4 = row.insertCell(3);
        var cell5 = row.insertCell(4);
        cell1.innerHTML += comp.getElementsByTagName("korSecnNm")[i].textContent;
        cell2.innerHTML += comp.getElementsByTagName("engSecnNm")[i].textContent;
        cell3.innerHTML += comp.getElementsByTagName("secnKacdNm")[i].textContent;
        cell4.innerHTML += comp.getElementsByTagName("issuDt")[i].textContent;
        cell5.innerHTML += comp.getElementsByTagName("shotnIsin")[i].textContent;
      }
    }
  });
  xhr.open("GET", "http://localhost:3000/webapi?word=" + companyname);
  xhr.send();
}

function stack_R() {

  document.getElementById('allot_info').style.display="table"
  document.getElementById('allot_info').style.visibility="visible"

  var xhr = new XMLHttpRequest();
  xhr.withCredentials = true;
  var companynum = document.querySelectorAll("input")[2].value;

  console.log(companynum);
  xhr.addEventListener("readystatechange", function() {
    if(this.readyState === 4) {

      parser = new DOMParser();
      var comn = parser.parseFromString(this.responseText,"text/xml");

      for( let i=0 ; i < 10 ; i++ ) {
        var table = document.getElementById('allot_info');
        var row = table.insertRow();
        var cell1 = row.insertCell(0);
        var cell2 = row.insertCell(1);
        var cell3 = row.insertCell(2);
        var cell4 = row.insertCell(3);
        cell1.innerHTML += comn.getElementsByTagName("stckIssuCmpyNm")[i].textContent;
        cell2.innerHTML += comn.getElementsByTagName("dvdnBasDt")[i].textContent;
        cell3.innerHTML += comn.getElementsByTagName("cashDvdnPayDt")[i].textContent;
        cell4.innerHTML += comn.getElementsByTagName("stckGenrDvdnAmt")[i].textContent;
      }
    }
  });
  xhr.open("GET", "http://localhost:3000/webapi2?word=" + companynum);
  xhr.send();
}

function index1() {
  alert('조회하고 싶은 회사명을 입력해주세요.')
  document.getElementById('basic_search').style.display="block"
  document.getElementById('basic_search').style.visibility="visible"
  document.getElementById('allot_search').style.display="block"
  document.getElementById('allot_search').style.visibility="visible"
}

function index2() {
  alert('위치를 찾고 싶은 회사명을 입력해주세요.')
}