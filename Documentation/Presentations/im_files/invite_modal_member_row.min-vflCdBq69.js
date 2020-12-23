define(["require","exports","tslib","react","spectrum/tertiary_link","spectrum/facepile/facepile_members_avatar","modules/core/i18n","modules/clean/analytics","modules/clean/static_urls","modules/clean/teams/admin/widgets/resend_invite_modal/resend_invite_modal","modules/clean/teams/admin/widgets/invite_modal/invite_modal_first_task/constants","modules/clean/teams/constants","modules/clean/react/member_sidebar_actions","modules/clean/teams/admin/widgets/invite_modal/invite_modal_first_task/invite_modal_member_data","modules/clean/teams/admin/widgets/invite_modal/invite_modal_first_task/invite_modal_role_dropdown","modules/clean/teams/admin/widgets/invite_modal/invite_modal_first_task/invite_modal_action_dropdown"],(function(e,t,a,i,n,l,r,m,o,s,d,_,c,u,v,f){"use strict";Object.defineProperty(t,"__esModule",{value:!0}),i=a.__importDefault(i);t.MemberName=function(e){var t=e.displayName,a=e.isCurrentUser,l=e.isInvited,m=e.onResendClick,o=i.default.createElement(i.default.Fragment,null,t);return a?o=i.default.createElement(i.default.Fragment,null,r.intl.formatMessage({id:"6mqD/l",defaultMessage:"{displayName} <b>(You)</b>"},{displayName:t,b:function(e){return i.default.createElement("b",null,e)}})):l&&(o=i.default.createElement(i.default.Fragment,null,r.intl.formatMessage({id:"80S+yG",defaultMessage:"{displayName}<row> · Invited · </row><link>Resend invite</link>"},{displayName:t,row:function(e){return i.default.createElement("span",{className:"member-row__dot"},e)},link:function(e){return i.default.createElement(n.TertiaryLink,{className:"member-row__invite-button",onClick:m},e)}}))),i.default.createElement("div",{className:"member-row__name"},o)},t.MemberRow=function(e){var a,n=e.id,r=e.member,b=e.actionsData,p=e.roleOptions,g=e.onRoleSelection,w=e.handleOnClose,N=e.tieredAdmin,E=e.isCurrentUser,A=void 0!==E&&E,M=e.growthActSmbMWInvitesActive,y=o.static_url("/static/images/growth/single-vflQ4gh9g.svg"),k=d.DEFAULT_ROLE_LABEL,I="",O="",R=!1,C=-1,D=d.MemberOption.label;r&&(y=r.team_join_state!==c.JoinState.PENDING?r.photo_url||"":o.static_url("/static/images/growth/member-vflJ3QUg7.svg"),k=r.display_name,I=r.email,O=r.initials,R=r.team_join_state===c.JoinState.PENDING,C=r.user_id,a=null!=r.admin_role&&r.admin_role!==_.ADMIN_ROLE.NONE?d.AdminOption.id:d.MemberOption.id,D=(function(e,t){void 0===t&&(t=!1);if(!u.isAdminRole(e.admin_role))return d.MemberOption.label;if(!t)return d.AdminOption.label;return _.ADMIN_ROLE_NAMES[e.admin_role]||d.AdminOption.label})(r,N));var S=!r,L=R&&!!I,h={user_id:C,module_name:"first_task_imm",framework:"team_setup_essential"};return i.default.createElement("div",{id:n,className:"member-row "+(S?"member-row--empty":"")},i.default.createElement(l.FacepileMembersAvatar,{avatarColorSeed:k,avatarSize:32,initials:O,photoUrl:y,active:!0,disabled:!0}),i.default.createElement("div",{className:"member-row__text-container"},i.default.createElement(t.MemberName,{displayName:k,isCurrentUser:A,isInvited:L,onResendClick:function(){m.TeamsWebActionsLogger.log("admin_resend_email_invite_open",h);var e=function(e){void 0===e&&(e=!1),m.TeamsWebActionsLogger.log(e?"admin_resend_email_invite":"admin_resend_email_invite_cancel",h),b&&b.onClose&&b.onClose()};s.showResendInviteModal({userId:C,email:I,onRequestClose:e,onPrimaryAction:function(){return e(!0)},onSecondaryAction:e}),w()}}),I&&i.default.createElement("div",{className:"member-row__email js-text-email"},I)),A&&i.default.createElement("span",{className:"member-row__admin-text js-text-role"},D),!A&&i.default.createElement(v.InviteModalRoleDropdown,{options:p,triggerLabel:D,selectedId:a,onSelection:g,className:"member-row__role-dropdown",isEmptyRow:S}),i.default.createElement(f.InviteModalActionDropdown,{actionsData:b,displayName:k,loggingExtras:h,handleOnClose:w,className:"member-row__action-dropdown",growthActSmbMWInvitesActive:M}))}}));
//# sourceMappingURL=invite_modal_member_row.min.js-vflr0Ei_I.map