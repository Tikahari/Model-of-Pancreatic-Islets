define("modules/clean/pnm/constants",["require","exports"],(function(_,e){"use strict";Object.defineProperty(e,"__esModule",{value:!0}),e.VAULT_PRE_SETUP_ACTION="life_vault_pre_setup",e.PASSWORDS_PRE_SETUP_ACTION="passwords_pre_setup",e.BACKUP_PRE_SETUP_ACTION="device_folder_pre_setup",e.VAULT_POST_SETUP_ACTION="life_vault_post_setup",e.PASSWORDS_POST_SETUP_ACTION="passwords_post_setup",e.PRE_SETUP_LINK_NODES=[e.VAULT_PRE_SETUP_ACTION,e.PASSWORDS_PRE_SETUP_ACTION,e.BACKUP_PRE_SETUP_ACTION],e.POST_SETUP_LINK_NODES=[e.VAULT_POST_SETUP_ACTION,e.PASSWORDS_POST_SETUP_ACTION],e.SUPPORTED_LINK_NODE_CLICK_ACTIONS=[e.PASSWORDS_POST_SETUP_ACTION].concat(e.PRE_SETUP_LINK_NODES)})),define("modules/clean/pnm/utils",["require","exports","modules/clean/pnm/constants"],(function(_,e,n){"use strict";function S(_){var e,n,S,P=null===(e=null==_?void 0:_.link_node)||void 0===e?void 0:e.action;return null!==(S=null!==(n=null==P?void 0:P[".tag"])&&void 0!==n?n:P)&&void 0!==S?S:null}Object.defineProperty(e,"__esModule",{value:!0}),e.getLinkNodeAction=S,e.isPreSetupLinkNode=function(_){var e=S(_);return!(!e||""===e)&&n.PRE_SETUP_LINK_NODES.includes(e)},e.hasValidLinkNode=function(_){var e=S(_);return!(!e||"unknown_action"===e)},e.isSupportedLinkNodeClickAction=function(_){var e=S(_);return!(!e||""===e)&&n.SUPPORTED_LINK_NODE_CLICK_ACTIONS.includes(e)}}));
//# sourceMappingURL=pkg-pnm.min.js-vfl5sbmhg.map