define(["require","exports","tslib","react","modules/core/i18n","modules/clean/viewer","modules/core/exception","modules/core/notify","dig-components/buttons","dig-components/modal","dig-components/typography","dig-components/text_fields","modules/clean/analytics","modules/clean/api_v2/default_team_client","modules/clean/react/css","modules/clean/teams/admin/widgets/groups/team_members_typeahead"],(function(e,t,a,r,n,o,s,l,i,u,d,c,m,g,f,p){"use strict";Object.defineProperty(t,"__esModule",{value:!0}),r=a.__importStar(r),t.createGroup=function(e,t,r){return void 0===r&&(r={".tag":"user_managed"}),a.__awaiter(void 0,void 0,void 0,(function(){return a.__generator(this,(function(a){switch(a.label){case 0:return[4,new g.DefaultTeamApiV2Client(e).ns("team").rpc("groups/create",{group_name:t,group_management_type:r,add_creator_as_owner:!0},{})];case 1:return[2,a.sent()]}}))}))},t.addMembers=function(e,t){return function(a){if(!t.length)return Promise.resolve(a);var r=a.group_id,n=t.map((function(e){return{user:{".tag":"email",email:e.email},access_type:{".tag":"member"}}}));return new g.DefaultTeamApiV2Client(e).ns("team").rpc("groups/members/add",{group:{".tag":"group_id",group_id:r},members:n},{}).then((function(){return a}))}},t.CreateGroupModal=f.requireCssWithComponent((function(e){var a=e.open,g=e.handleOnClose,f=e.memberList,_=e.showAddMembers,M=r.useState(),v=M[0],h=M[1],b=r.useState(),w=b[0],E=b[1],y=r.useState([]),C=y[0],T=y[1],x=o.Viewer.get_viewer().work_user;r.useEffect((function(){m.TeamsWebActionsLogger.log("create_group_invite_modal_impression")}),[]);var N=function(){return m.TeamsWebActionsLogger.log("create_group_invite_modal_click",{group_name:v}),x?v&&t.createGroup(x,v).then(t.addMembers(x,C)).then(g).catch((function(){m.TeamsWebActionsLogger.log("create_group_invite_error",{group_name:v}),E(n.intl.formatMessage({id:"8nZWnh",defaultMessage:"Enter a valid group name"}))})):(s.reportException({err:new Error("No work user associated with viewer"),severity:s.SEVERITY.CRITICAL}),void l.Notify.error(n.intl.formatMessage({id:"wfJMlq",defaultMessage:"There was an error completing this request."})))};return r.default.createElement(u.Modal,{open:a,className:"create-group-modal",overlayClassName:"create-group-modal__overlay",width:"small",withCloseButton:n.intl.formatMessage({id:"lNU//O",defaultMessage:"Close Modal"}),onRequestClose:function(){return g()}},r.default.createElement(u.Modal.Header,{hasBottomSpacing:"title-standard"},r.default.createElement(d.Title,null,n.intl.formatMessage({id:"cyZ70Z",defaultMessage:"Create new group"}))),r.default.createElement(u.Modal.Body,null,r.default.createElement(d.Text,{isBold:!0},n.intl.formatMessage({id:"67fhSx",defaultMessage:"Group name"})),r.default.createElement(c.TextInput,{autoFocus:!0,placeholder:n.intl.formatMessage({id:"38o/9Q",defaultMessage:"Marketing, Finance, Design, etc."}),value:v,onChange:function(e){return h(e.currentTarget.value)},onKeyDown:function(e){return"Enter"===e.key&&N()}}),w&&r.default.createElement(d.Text,{tagName:"p",color:"error"},w),_&&f&&f.length&&r.default.createElement("div",{className:"create-group-add-members"},r.default.createElement(d.Text,{isBold:!0},n.intl.formatMessage({id:"6cNXJ3",defaultMessage:"Add team members"})),r.default.createElement(p.TeamMembersTypeahead,{memberList:f,selected:C,onChange:T,userId:null==x?void 0:x.id})),r.default.createElement(d.Text,{tagName:"p"},n.intl.formatMessage({id:"VRIKXC",defaultMessage:"Only you can add members to this group"}))),r.default.createElement(u.Modal.Footer,null,r.default.createElement(i.Button,{variant:"outline",className:"js-cancel-button",onClick:function(){return g()}},n.intl.formatMessage({id:"d9/SE1",defaultMessage:"Cancel"})),r.default.createElement(i.Button,{variant:"primary",className:"js-create-button",onClick:N,disabled:!v},n.intl.formatMessage({id:"WgscFw",defaultMessage:"Create group"}))))}),["/static/css/dig-components/index.web-vflSjAPFK.css","/static/css/teams/admin/widgets/groups/create_group_modal-vflykS9VT.css"])}));
//# sourceMappingURL=create_group_modal.min.js-vflkST-Nq.map