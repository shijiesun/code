package greensdksample

import (
	"net/http"
	"encoding/json"
	"net/url"
	"strings"
	"io/ioutil"
	"fmt"
)

type DefaultClient struct {
	Profile Profile;
}

func (defaultClient DefaultClient) GetResponse(path string, clinetInfo ClinetInfo, bizDataJson string) string{
	clientInfoJson, _ := json.Marshal(clinetInfo)

	client := &http.Client{}

	fmt.Println(host + path + "?clientInfo=" + url.QueryEscape(string(clientInfoJson)))
	
	req, err := http.NewRequest(method, host + path + "?clientInfo=" + url.QueryEscape(string(clientInfoJson)), strings.NewReader(bizDataJson))

	if err != nil {
		// handle error
		return ErrorResult(err)
	} else {
		addRequestHeader(bizDataJson, req, string(clientInfoJson), path, defaultClient.Profile.AccessKeyId, defaultClient.Profile.AccessKeySecret)

		response, _ := client.Do(req)

		defer response.Body.Close()

		body, err := ioutil.ReadAll(response.Body)
		if(err != nil) {
			// handle error
			return ErrorResult(err)
		} else {
			return string(body)
		}
	}
}

type IAliYunClient interface {
	GetResponse(path string, clinetInfo ClinetInfo, bizDataJson string) string
}
