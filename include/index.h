const char index_html[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>

<head>
<meta name="viewport" content="width=device-width, initial-scale=1.0">
<style>
.card{
  max-width: 400px;
  min-height: 250px;
  background: #027875;
  padding: 30px;
  box-sizing: border-box;
  border-radius: 25px;
  color: #FFF;
  margin:20px;
  box-shadow: 0px 2px 18px -4px rgba(0,0,0,0.75);
}
.t1 {
  margin-left: auto;
  margin-right: auto;
  width: 100%;
  margin: 0px;
  padding: 0px;
  border: 0px solid black;
}
.td1 {
  margin: 0px;
  padding: 0px;
  border: 0px solid black;
  text-align:right;
}
.td2 {
  margin: 0px;
  padding: 0px;
  border: 0px solid black;
}
.td3 {
  margin: 0px;
  padding: 0px;
  border: 0px solid black;
}
.text {
 type:text;
 width:2em;
}
</style>
<link rel="shortcut icon" href="#">
<script>
    requestData(); // get intial data straight away 
  
    // request data updates every 5000 milliseconds
    //setInterval(requestData, 5000);

    function requestData() {

      var xhr = new XMLHttpRequest();
      xhr.open('GET', 'values');

      xhr.onload = function() {
        if (xhr.status === 200) {

          if (xhr.responseText) { // if the returned data is not null, update the values

            var data = JSON.parse(xhr.responseText);

            document.getElementById("opm_octoprint_ip").value  = data.opm_octoprint_ip;
            document.getElementById("opm_octoprint_port").value  = data.opm_octoprint_port;
            document.getElementById("opm_octoprint_api").value  = data.opm_octoprint_api;
            document.getElementById("opm_timezone").value  = data.opm_timezone;
            document.getElementById("opm_version").innerHTML   = data.opm_version;

          } else { // a problem occurred
			      document.getElementById("valueBox").hidden = false
          }
        } else {
          console.log('Request failed.  Returned status of ' + xhr.status);
  		  document.getElementById("valueBox").hidden = false
        }
      };
      
      xhr.send();
    }

    function submitForm(that) {
      var obj = new Object();

  	  obj.opm_octoprint_ip = that.opm_octoprint_ip.value;
  	  obj.opm_octoprint_port = that.opm_octoprint_port.value;
  	  obj.opm_octoprint_api = that.opm_octoprint_api.value;
  	  obj.opm_timezone = that.opm_timezone.value;
      
      var jsonString = JSON.stringify(obj);
      console.log(jsonString);

      var xhr = new XMLHttpRequest();
      var url = document.location;
      xhr.open("POST", url, true);
      xhr.setRequestHeader("Content-Type", "application/json");
      xhr.onreadystatechange = function () {
          if (xhr.readyState === 4 && xhr.status === 200) {
              var json = JSON.parse(xhr.responseText);
              console.log(json);
          }
      };
  	  xhr.send(jsonString);
      return false;
    }
  </script>
</head>

<body>
	<div class="card">
      <h1 style="text-align:center;" >OctoPrintMon </h1>
      <form onsubmit="submitForm(this)">
      <span id="valueBox">
      <table class="t1">
      <tr></tr>
      <tr>
        <td class="td1">OctroPrint IP</td>
        <td class="td2">:</td>
        <td class="td3">&nbsp;<input id="opm_octoprint_ip" value=""/></td>
      </tr>
      <tr></tr>
      <tr>
        <td class="td1">OctroPrint Port</td>
        <td class="td2">:</td>
        <td class="td3">&nbsp;<input id="opm_octoprint_port" value=""/></td>
      </tr>      
      <tr></tr>
      <tr>
        <td class="td1">OctroPrint API</td>
        <td class="td2">:</td>
        <td class="td3">&nbsp;<input id="opm_octoprint_api" value=""/></td>
      </tr>      
      <tr></tr>
      <tr>
        <td class="td1">Timezone</td>
        <td class="td2">:</td>
        <td class="td3">&nbsp;<input id="opm_timezone" value=""/></td>
      </tr>      
      </table>
	  </span><br>
      <button>Submit</button>
      </form>      
      <div style="text-align: center;"><small>(version:<span id="opm_version"></span>)</small></div>
	</div>
</body>

</html>
)=====";