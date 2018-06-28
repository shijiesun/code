package greensdksample

type ClinetInfo struct {
	SdkVersion 	string	`json:"sdkVersion"`
	CfgVersion 	string	`json:"cfgVersion"`
	UserType 	string	`json:"userType"`
	UserId 		string	`json:"userId"`
	UserNick 	string	`json:"userNick"`
	Avatar 		string	`json:"avatar"`
	Imei		string	`json:"imei"`
	Imsi		string	`json:"imsi"`
	Umid		string	`json:"umid"`
	Ip		string	`json:"ip"`
	Os		string	`json:"os"`
	Channel		string	`json:"channel"`
	HostAppName	string	`json:"hostAppName"`
	HostPackage	string	`json:"hostPackage"`
	HostVersion	string	`json:"hostVersion"`
}

type Task struct {
	DataId string		`json:"dataId"`
	Url string		`json:"url"`
	Extras map[string]string   `json:"extras"`
}

type BizData struct {
	Scenes 	[]string	`json:"scenes"`
	Tasks	[]Task		`json:"tasks"`
}

type GetPersonsRequest struct {
	GroupId string          `json:"groupId"`
}

type AddPersonRequest struct {
	PersonId string         `json:"personId"`
	GroupIds []string       `json:"groupIds"`
}
