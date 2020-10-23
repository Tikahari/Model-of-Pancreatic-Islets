define(["require","exports","tslib","react","spectrum/button","classnames","modules/core/notify","modules/core/i18n","modules/clean/ajax","modules/constants/trademark","modules/clean/react/css","modules/clean/react/modal","modules/clean/payments/validation","modules/clean/teams/admin/types/constants","modules/clean/teams/admin/widgets/update_billing_modal/update_billing_modal","modules/clean/react/payments/error/browser_update_required_modal","modules/clean/static_urls","modules/clean/react/payments/unified_module/unified_payment_form_async"],(function(e,t,a,n,o,s,r,i,l,d,u,c,m,p,f,g,y,b){"use strict";Object.defineProperty(t,"__esModule",{value:!0}),n=a.__importDefault(n),s=a.__importDefault(s),l=a.__importStar(l);var _=(function(e){function u(){var t=null!==e&&e.apply(this,arguments)||this;return t.state={loadingContent:!0,submitting:!1,hasError:!1},t.handleLoadFailure=function(){r.Notify.error(i.intl.formatMessage({id:"C2BKnZ",defaultMessage:"Failed to load modal."})),c.Modal.close(),t.props.onClose&&t.props.onClose()},t.onAccept=function(){t.updateBillingModal&&t.updateBillingModal.onAccept(),t.unifiedPaymentFormAsync&&t.unifiedPaymentFormAsync.onAccept()},t.onDismiss=function(){t.updateBillingModal&&t.updateBillingModal.onDismiss(),c.Modal.close(),t.props.onClose&&t.props.onClose()},t.onSuccess=function(){t.props.onSuccess&&t.props.onSuccess()},t.saveUnifiedPaymentFormAsync=function(e){t.unifiedPaymentFormAsync=e},t.saveUpdateBillingModal=function(e){t.updateBillingModal=e},t.setSubmittingStatus=function(e){t.setState((function(t){return a.__assign(a.__assign({},t),{submitting:e})}))},t}return a.__extends(u,e),u.showInstance=function(e,a){c.Modal.showInstance(n.default.createElement(t.UpdateBillingModalLoader,{onClose:e,onSuccess:a}))},u.prototype.componentDidMount=function(){var e=this;l.WebRequest({url:"/account/team/update_billing_modal_view_model",success:function(t){var n=JSON.parse(t);n.isError?n.errorType===p.TeamBillingErrorType.SUBSCRIPTION_EXPIRED?e.setState({loadingContent:!1,hasError:!0,errorType:n.errorType}):n.errorType===p.TeamBillingErrorType.UNSUPPORTED_BROWSER?(e.handleLoadFailure(),g.BrowserUpdateModalLoader.showInstance()):e.handleLoadFailure():e.setState((function(e){return a.__assign(a.__assign({},e),{loadedProps:{countryList:n.countryList,iframeUrl:n.iframeUrl,vat:n.vat,userInfo:n.userInfo,countryToCurrencyMap:n.countryToCurrencyMap,countryCode:n.countryCode,serializedPaymentFormSpec:n.serializedPaymentFormSpec,requestId:n.requestId,submitSeq:0,unifiedPayment:n.unifiedPayment},loadingContent:!1})}))},error:function(){e.handleLoadFailure()}})},u.prototype.renderLoading=function(){return n.default.createElement("div",{className:"loading-spinner"},n.default.createElement("img",{src:y.static_url("/static/images/icons/ajax-loading-small-vfl3Wt7C_.gif"),alt:i.intl.formatMessage({id:"jybGUg",defaultMessage:"Loading"})}))},u.prototype.renderSubscriptionExpired=function(){return n.default.createElement("div",{className:"subscription-expired"},n.default.createElement("h3",{className:"subscription-expired--header"},i.intl.formatMessage({id:"JsiRXI",defaultMessage:"Your subscription has expired"})),n.default.createElement("div",{className:"subscription-expired--copy"},i.intl.formatMessage({id:"Ct4owd",defaultMessage:"To change your billing information, please first renew your {trademark_business} account. During the renewal process you’ll be able to choose a different payment method."},{trademark_business:d.TRADEMARK_BUSINESS})))},u.prototype.renderSubscriptionExpiredButtons=function(){return n.default.createElement("div",{className:"subscription-expired--buttons"},n.default.createElement("a",{href:"/team/renew",className:"subscription-expired--button c-btn c-btn--primary"},i.intl.formatMessage({id:"q9bBTQ",defaultMessage:"Renew Your Account"})))},u.prototype.renderContent=function(){if(this.state.loadedProps&&this.state.loadedProps.unifiedPayment)return n.default.createElement(b.UnifiedPaymentFormAsync,{isSubmittingStatus:this.setSubmittingStatus,onSuccess:this.onSuccess,ref:this.saveUnifiedPaymentFormAsync,isTeam:!0});var e=this.state.loadedProps,t=e.countryList,a=e.iframeUrl,o=e.countryToCurrencyMap,s=e.countryCode,r=e.serializedPaymentFormSpec,i=e.vat,l=e.userInfo,d=e.requestId;return n.default.createElement(f.UpdateBillingModal,{iframeUrl:a,countryList:t,countryToCurrencyMap:o,countryCode:s,onSuccess:this.onSuccess,ref:this.saveUpdateBillingModal,serializedPaymentFormSpec:r,setSubmittingStatus:this.setSubmittingStatus,vat:i,userInfo:l,requestId:d})},u.prototype.renderContentButtons=function(){var e=this.state,t=e.loadingContent,a=e.submitting,s=e.loadedProps,r=e.hasError,l=null;if(s){var d=s.countryCode,u=m.hasVat(d)?i.intl.formatMessage({id:"RCr4JC",defaultMessage:"Please note: changing your billing location or VAT number could impact your applicable tax rate."}):i.intl.formatMessage({id:"8vkOAo",defaultMessage:"Please note: changing your billing location could impact your applicable tax rate."});l=n.default.createElement("div",{className:"db-modal-lower-left-message"},u)}return n.default.createElement(c.ModalButtons,{className:"oq-modal__buttons"},l,n.default.createElement(o.Button,{className:"cancel-button",variant:"secondary",onClick:this.onDismiss},i.intl.formatMessage({id:"d9/SE1",defaultMessage:"Cancel"})),n.default.createElement(o.Button,{disabled:t||a||r,variant:"primary",onClick:this.onAccept},i.intl.formatMessage({id:"F5NZs5",defaultMessage:"Save changes"})))},u.prototype.render=function(){var e,t=this.state,a=t.loadingContent,o=t.hasError,r=t.errorType,l=null;a?e=this.renderLoading():o&&r===p.TeamBillingErrorType.SUBSCRIPTION_EXPIRED?(e=this.renderSubscriptionExpired(),l=this.renderSubscriptionExpiredButtons()):(e=this.renderContent(),l=this.renderContentButtons());return n.default.createElement(c.Modal,{className:s.default(["update-billing-modal","update-billing-modal-maestro"]),autoClose:!1,buttonComponent:l,title:o?null:i.intl.formatMessage({id:"yO4V6k",defaultMessage:"Update billing information"}),onDismiss:this.props.onClose},n.default.createElement("div",{className:"dynamic-content"},e))},u})(n.default.Component);t.UpdateBillingModalLoaderView=_,t.UpdateBillingModalLoader=u.requireCssWithComponent(_,["/static/css/teams/admin/widgets/update_billing_modal/update_billing_modal-vflpY1UuK.css"])}));
//# sourceMappingURL=update_billing_modal_loader.min.js-vflDRXHYn.map