define(["require","exports","tslib","react","dig-components/controls","modules/clean/react/teams/avatar/components","modules/core/i18n"],(function(e,t,a,r,s,l,m){"use strict";Object.defineProperty(t,"__esModule",{value:!0}),r=a.__importDefault(r),t.SuggestedMembersCheckboxes=function(e){var t=e.emails,n=e.toggleCheckboxCallback,o=e.suggestions;if(0===o.length)return null;var u=o.map((function(e){var o="";e.num_team_shared_members?o=m.intl.formatMessage({id:"mG6ORh",defaultMessage:"{count, plural, one{Already working with 1 team member} other{Already working with {count} team members}}"},{count:e.num_team_shared_members}):e.num_team_shared_folders&&(o=m.intl.formatMessage({id:"pMvVuy",defaultMessage:"{count, plural, one{Already sharing 1 folder with your team} other{Already sharing {count} folders with your team}}"},{count:e.num_team_shared_folders}));return r.default.createElement("li",{className:"suggested-members__item",key:e.user_id},r.default.createElement(s.Checkbox,{name:""+e.user_id,className:"suggested-members__checkbox",checked:t.includes(e.email),onChange:function(t){var a=t.target.checked;n(a,e.email)}}),r.default.createElement(l.TeamUserAvatar,a.__assign({name:e.display_name,email:e.email},e.photo_url?{photo_url:e.photo_url}:{},{context:o})))}));return r.default.createElement("div",null,r.default.createElement("ul",{className:"suggested-members__list-container"},u))},t.SuggestedMembersCheckboxes.displayName="SuggestedMembersCheckboxes"}));
//# sourceMappingURL=suggested_members.min.js-vflpoT0BK.map