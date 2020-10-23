define(["require","exports","tslib","react","modules/core/i18n","modules/clean/viewer","modules/core/exception","modules/core/notify","spectrum/typeahead","dig-components/icons/src","dig-components/typography","dig-components/icons","dig-components/avatar","modules/clean/analytics","modules/clean/api_v2/default_team_client","modules/clean/react/css","modules/clean/teams/admin/widgets/groups/create_group_modal","modules/clean/teams/admin/widgets/groups/util"],(function(e,t,r,n,o,a,u,i,s,l,c,g,m,d,p,_,f,v){"use strict";Object.defineProperty(t,"__esModule",{value:!0}),n=r.__importStar(n);var h={group_name:o.intl.formatMessage({id:"J54snd",defaultMessage:"Create new group"}),group_id:"",group_management_type:{".tag":"other"}},w=function(e){var t=e.token,r=e.query;return t===h?n.default.createElement(n.default.Fragment,null,n.default.createElement(g.UIIcon,{className:"group-suggestion-icon",src:l.AddCircleFill}),n.default.createElement(c.Text,null,r?o.intl.formatMessage({id:"j/dwP3",defaultMessage:'Create "{group_name}"'},{group_name:r}):t.group_name)):n.default.createElement(n.default.Fragment,null,n.default.createElement("div",{className:"group-suggestion-icon"},n.default.createElement(m.Avatar,{size:"small",hasNoOutline:!0,backgroundColor:m.avatarColorForUserIdentifier(v.getInitials(t.group_name))},v.getInitials(t.group_name))),n.default.createElement("div",{className:"group-suggestion-info"},n.default.createElement(c.Text,null,t.group_name),n.default.createElement(c.Text,{size:"small",color:"faint"},o.intl.formatMessage({id:"XMHn5C",defaultMessage:"{count, plural, one{# member} other{# members}}"},{count:t.member_count||0}))))};t.fetchGroups=function(e){return void 0===e&&(e=!0),r.__awaiter(void 0,void 0,void 0,(function(){return r.__generator(this,(function(t){switch(t.label){case 0:return[4,new p.DefaultTeamApiV2Client(a.Viewer.get_viewer().work_user).ns("team").rpc("groups/list",{limit:1e3},{}).then((function(t){if(!e)return t.groups;var r=t.groups.reduce((function(e,t){return"system_managed"===t.group_management_type[".tag"]&&(t.member_count||0)>=(e.member_count||0)?t:e})).group_id;return t.groups.filter((function(e){return e.group_id!==r}))}))];case 1:return[2,t.sent()]}}))}))},t.groupExists=function(e,t){return e.some((function(e){return e.group_name.toLocaleLowerCase()===t.toLocaleLowerCase()}))},t.GroupsTypeahead=_.requireCssWithComponent((function(e){var l=e.selected,c=e.groups,g=void 0===c?[]:c,m=e.onChange,p=e.onCreate,_=e.onInputChange,v=e.handleCreateModal,y=n.useState(!1),C=y[0],b=y[1],E=n.useState(),T=E[0],M=E[1],x=n.useState([]),L=x[0],k=x[1];n.useEffect((function(){return null==v?void 0:v(C)}),[C]),n.useEffect((function(){return null==_?void 0:_(T)}),[T]),n.useEffect((function(){return A()}),[l,g]);var A=function(e){M(e),k(r.__spreadArrays([h],g.reduce((function(t,r){return l.find((function(e){return e.group_id===r.group_id}))?t:(e?r.group_name.toLocaleLowerCase().indexOf(e.toLocaleLowerCase())>-1&&t.push(r):t.push(r),t)}),[]).sort((function(e,t){return e.group_name.localeCompare(t.group_name)}))))};return n.default.createElement(s.Typeahead,{height:200,listItemHeight:48,className:"groups-typeahead",inputProps:{placeholder:l.length?void 0:o.intl.formatMessage({id:"Hh48DQ",defaultMessage:"Select or create group"})},onChange:A,onRemoveToken:function(e){d.TeamsWebActionsLogger.log("invite_member_delete_group",{group_name:name}),m(l.filter((function(t){return t.group_id!==e.group_id})))},onSelect:function(e,n,s){if(e===h){if(!s)return d.TeamsWebActionsLogger.log("invite_member_create_group_click"),void b(!0);if(!t.groupExists(g,s)){var c=a.Viewer.get_viewer().work_user;if(!c)return u.reportException({err:new Error("No work user associated with viewer"),severity:u.SEVERITY.CRITICAL}),i.Notify.error(o.intl.formatMessage({id:"wfJMlq",defaultMessage:"There was an error completing this request."})),void M(void 0);d.TeamsWebActionsLogger.log("invite_member_create_group_inline",{group_name:s}),f.createGroup(c,s).then((function(e){var t={group_id:e.group_id,group_name:e.group_name,group_external_id:e.group_external_id,group_management_type:e.group_management_type,member_count:e.member_count};null==p||p(t)})).catch((function(){return(function(e){d.TeamsWebActionsLogger.log("invite_member_create_group_inline_error",{group_name:e}),m(r.__spreadArrays(l,[{group_name:e,group_id:e+"-invalid",group_management_type:{".tag":"other"},variant:"error"}])),M(void 0)})(s)}))}M(void 0)}var _=g.find((function(t){return t.group_id===e.group_id}));_&&m(r.__spreadArrays(l,[_]))},renderSuggestion:function(e){return n.default.createElement(w,{token:e,query:T})},renderTokenContent:function(e){return n.default.createElement(n.default.Fragment,null,e.group_name)},suggestions:L,tokens:l.map((function(e){return{key:e.group_id,variant:e.variant||"default",content:e}}))})}),["/static/css/spectrum/index.web-vfl6Z83yw.css","/static/css/dig-components/index.web-vflSjAPFK.css","/static/css/teams/admin/widgets/groups/groups_typeahead-vfli8OYdu.css"])}));
//# sourceMappingURL=groups_typeahead.min.js-vflm3TaR2.map