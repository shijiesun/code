package facesdk

import (
	"encoding/json"
	"fmt"
	"uuid"
	"greensdksample"
)

const accessKeyId string = "LTAIEqr3BDEtynue"
const accessKeySecret string = "WXdTfFbwWDrRsykZfv7NSjadmWr38m"

func FaceGetPersons() {
	profile := greensdksample.Profile{AccessKeyId:accessKeyId, AccessKeySecret:accessKeySecret}

	path := "/green/sface/group/persons"
	
	clientInfo := greensdksample.ClinetInfo{Ip:"127.0.0.1"}

	req := greensdksample.GetPersonsRequest{GroupId:"dahuitang"}
	reqjson, _ := json.Marshal(req)
	
	var client greensdksample.IAliYunClient = greensdksample.DefaultClient{Profile:profile}

	// your biz code
	fmt.Println(client.GetResponse(path, clientInfo, string(reqjson)))
}

func FaceAddPerson() {
	profile := greensdksample.Profile{AccessKeyId:accessKeyId, AccessKeySecret:accessKeySecret}

	path := "/green/sface/person/add"
	clientInfo := greensdksample.ClinetInfo{Ip:"127.0.0.1"}

	personId := "abc"
	groupIds := []string{"dahuitang"}
	req := greensdksample.AddPersonRequest{personId, groupIds}
	reqjson, _ := json.Marshal(req)
	
	var client greensdksample.IAliYunClient = greensdksample.DefaultClient{Profile:profile}

	// your biz code
	fmt.Println(client.GetResponse(path, clientInfo, string(reqjson)))
}


func FaceScan(){
	profile := greensdksample.Profile{AccessKeyId:accessKeyId, AccessKeySecret:accessKeySecret}

	path := "/green/image/scan"
	
	clientInfo := greensdksample.ClinetInfo{Ip:"127.0.0.1"}

	// 构造请求数据
	scenes := []string{"sface-n"}

	extras := map[string]string {
		"groupId": "dahuitang",
	}
	
	task := greensdksample.Task{DataId:uuid.Rand().Hex(), Url:"https://dahuitang.oss-cn-beijing.aliyuncs.com/yz1.jpg", Extras:extras}
	tasks := []greensdksample.Task{task}

	bizData := greensdksample.BizData{ scenes, tasks}
	bizDataJson, _ := json.Marshal(bizData)
	
	var client greensdksample.IAliYunClient = greensdksample.DefaultClient{Profile:profile}

	// your biz code
	fmt.Println(client.GetResponse(path, clientInfo, string(bizDataJson)))

}
